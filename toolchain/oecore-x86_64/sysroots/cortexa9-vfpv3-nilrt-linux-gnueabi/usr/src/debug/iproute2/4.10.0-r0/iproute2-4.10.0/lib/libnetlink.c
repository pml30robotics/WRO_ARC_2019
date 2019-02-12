/*
 * libnetlink.c	RTnetlink service routines.
 *
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		as published by the Free Software Foundation; either version
 *		2 of the License, or (at your option) any later version.
 *
 * Authors:	Alexey Kuznetsov, <kuznet@ms2.inr.ac.ru>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <syslog.h>
#include <fcntl.h>
#include <net/if_arp.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/uio.h>

#include "libnetlink.h"

#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

int rcvbuf = 1024 * 1024;

void rtnl_close(struct rtnl_handle *rth)
{
	if (rth->fd >= 0) {
		close(rth->fd);
		rth->fd = -1;
	}
}

int rtnl_open_byproto(struct rtnl_handle *rth, unsigned int subscriptions,
		      int protocol)
{
	socklen_t addr_len;
	int sndbuf = 32768;

	memset(rth, 0, sizeof(*rth));

	rth->proto = protocol;
	rth->fd = socket(AF_NETLINK, SOCK_RAW | SOCK_CLOEXEC, protocol);
	if (rth->fd < 0) {
		perror("Cannot open netlink socket");
		return -1;
	}

	if (setsockopt(rth->fd, SOL_SOCKET, SO_SNDBUF,
		       &sndbuf, sizeof(sndbuf)) < 0) {
		perror("SO_SNDBUF");
		return -1;
	}

	if (setsockopt(rth->fd, SOL_SOCKET, SO_RCVBUF,
		       &rcvbuf, sizeof(rcvbuf)) < 0) {
		perror("SO_RCVBUF");
		return -1;
	}

	memset(&rth->local, 0, sizeof(rth->local));
	rth->local.nl_family = AF_NETLINK;
	rth->local.nl_groups = subscriptions;

	if (bind(rth->fd, (struct sockaddr *)&rth->local,
		 sizeof(rth->local)) < 0) {
		perror("Cannot bind netlink socket");
		return -1;
	}
	addr_len = sizeof(rth->local);
	if (getsockname(rth->fd, (struct sockaddr *)&rth->local,
			&addr_len) < 0) {
		perror("Cannot getsockname");
		return -1;
	}
	if (addr_len != sizeof(rth->local)) {
		fprintf(stderr, "Wrong address length %d\n", addr_len);
		return -1;
	}
	if (rth->local.nl_family != AF_NETLINK) {
		fprintf(stderr, "Wrong address family %d\n",
			rth->local.nl_family);
		return -1;
	}
	rth->seq = time(NULL);
	return 0;
}

int rtnl_open(struct rtnl_handle *rth, unsigned int subscriptions)
{
	return rtnl_open_byproto(rth, subscriptions, NETLINK_ROUTE);
}

int rtnl_wilddump_request(struct rtnl_handle *rth, int family, int type)
{
	return rtnl_wilddump_req_filter(rth, family, type, RTEXT_FILTER_VF);
}

int rtnl_wilddump_req_filter(struct rtnl_handle *rth, int family, int type,
			    __u32 filt_mask)
{
	struct {
		struct nlmsghdr nlh;
		struct ifinfomsg ifm;
		/* attribute has to be NLMSG aligned */
		struct rtattr ext_req __attribute__ ((aligned(NLMSG_ALIGNTO)));
		__u32 ext_filter_mask;
	} req = {
		.nlh.nlmsg_len = sizeof(req),
		.nlh.nlmsg_type = type,
		.nlh.nlmsg_flags = NLM_F_DUMP | NLM_F_REQUEST,
		.nlh.nlmsg_seq = rth->dump = ++rth->seq,
		.ifm.ifi_family = family,
		.ext_req.rta_type = IFLA_EXT_MASK,
		.ext_req.rta_len = RTA_LENGTH(sizeof(__u32)),
		.ext_filter_mask = filt_mask,
	};

	return send(rth->fd, &req, sizeof(req), 0);
}

int rtnl_wilddump_req_filter_fn(struct rtnl_handle *rth, int family, int type,
				req_filter_fn_t filter_fn)
{
	struct {
		struct nlmsghdr nlh;
		struct ifinfomsg ifm;
		char buf[1024];
	} req = {
		.nlh.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifinfomsg)),
		.nlh.nlmsg_type = type,
		.nlh.nlmsg_flags = NLM_F_DUMP | NLM_F_REQUEST,
		.nlh.nlmsg_seq = rth->dump = ++rth->seq,
		.ifm.ifi_family = family,
	};
	int err;

	if (!filter_fn)
		return -EINVAL;

	err = filter_fn(&req.nlh, sizeof(req));
	if (err)
		return err;

	return send(rth->fd, &req, req.nlh.nlmsg_len, 0);
}

int rtnl_wilddump_stats_req_filter(struct rtnl_handle *rth, int fam, int type,
				   __u32 filt_mask)
{
	struct {
		struct nlmsghdr nlh;
		struct if_stats_msg ifsm;
	} req;

	memset(&req, 0, sizeof(req));
	req.nlh.nlmsg_len = NLMSG_LENGTH(sizeof(struct if_stats_msg));
	req.nlh.nlmsg_type = type;
	req.nlh.nlmsg_flags = NLM_F_DUMP|NLM_F_REQUEST;
	req.nlh.nlmsg_pid = 0;
	req.nlh.nlmsg_seq = rth->dump = ++rth->seq;
	req.ifsm.family = fam;
	req.ifsm.filter_mask = filt_mask;

	return send(rth->fd, &req, sizeof(req), 0);
}

int rtnl_send(struct rtnl_handle *rth, const void *buf, int len)
{
	return send(rth->fd, buf, len, 0);
}

int rtnl_send_check(struct rtnl_handle *rth, const void *buf, int len)
{
	struct nlmsghdr *h;
	int status;
	char resp[1024];

	status = send(rth->fd, buf, len, 0);
	if (status < 0)
		return status;

	/* Check for immediate errors */
	status = recv(rth->fd, resp, sizeof(resp), MSG_DONTWAIT|MSG_PEEK);
	if (status < 0) {
		if (errno == EAGAIN)
			return 0;
		return -1;
	}

	for (h = (struct nlmsghdr *)resp; NLMSG_OK(h, status);
	     h = NLMSG_NEXT(h, status)) {
		if (h->nlmsg_type == NLMSG_ERROR) {
			struct nlmsgerr *err = (struct nlmsgerr *)NLMSG_DATA(h);

			if (h->nlmsg_len < NLMSG_LENGTH(sizeof(struct nlmsgerr)))
				fprintf(stderr, "ERROR truncated\n");
			else
				errno = -err->error;
			return -1;
		}
	}

	return 0;
}

int rtnl_dump_request(struct rtnl_handle *rth, int type, void *req, int len)
{
	struct nlmsghdr nlh = {
		.nlmsg_len = NLMSG_LENGTH(len),
		.nlmsg_type = type,
		.nlmsg_flags = NLM_F_DUMP | NLM_F_REQUEST,
		.nlmsg_seq = rth->dump = ++rth->seq,
	};
	struct sockaddr_nl nladdr = { .nl_family = AF_NETLINK };
	struct iovec iov[2] = {
		{ .iov_base = &nlh, .iov_len = sizeof(nlh) },
		{ .iov_base = req, .iov_len = len }
	};
	struct msghdr msg = {
		.msg_name = &nladdr,
		.msg_namelen = sizeof(nladdr),
		.msg_iov = iov,
		.msg_iovlen = 2,
	};

	return sendmsg(rth->fd, &msg, 0);
}

int rtnl_dump_request_n(struct rtnl_handle *rth, struct nlmsghdr *n)
{
	struct sockaddr_nl nladdr = { .nl_family = AF_NETLINK };
	struct iovec iov = {
		.iov_base = n,
		.iov_len = n->nlmsg_len
	};
	struct msghdr msg = {
		.msg_name = &nladdr,
		.msg_namelen = sizeof(nladdr),
		.msg_iov = &iov,
		.msg_iovlen = 1,
	};

	n->nlmsg_flags = NLM_F_DUMP|NLM_F_REQUEST;
	n->nlmsg_pid = 0;
	n->nlmsg_seq = rth->dump = ++rth->seq;

	return sendmsg(rth->fd, &msg, 0);
}

static int rtnl_dump_done(const struct rtnl_handle *rth,
			  struct nlmsghdr *h)
{
	int len = *(int *)NLMSG_DATA(h);

	if (rth->proto == NETLINK_SOCK_DIAG) {
		if (h->nlmsg_len < NLMSG_LENGTH(sizeof(int))) {
			fprintf(stderr, "DONE truncated\n");
			return -1;
		}


		if (len < 0) {
			errno = -len;
			if (errno == ENOENT || errno == EOPNOTSUPP)
				return -1;
			perror("RTNETLINK answers");
			return len;
		}
	}
	return 0;
}

static void rtnl_dump_error(const struct rtnl_handle *rth,
			    struct nlmsghdr *h)
{

	if (h->nlmsg_len < NLMSG_LENGTH(sizeof(struct nlmsgerr))) {
		fprintf(stderr, "ERROR truncated\n");
	} else {
		const struct nlmsgerr *err = (struct nlmsgerr *)NLMSG_DATA(h);

		errno = -err->error;
		if (rth->proto == NETLINK_SOCK_DIAG &&
		    (errno == ENOENT ||
		     errno == EOPNOTSUPP))
			return;

		perror("RTNETLINK answers");
	}
}

int rtnl_dump_filter_l(struct rtnl_handle *rth,
		       const struct rtnl_dump_filter_arg *arg)
{
	struct sockaddr_nl nladdr;
	struct iovec iov;
	struct msghdr msg = {
		.msg_name = &nladdr,
		.msg_namelen = sizeof(nladdr),
		.msg_iov = &iov,
		.msg_iovlen = 1,
	};
	char buf[32768];
	int dump_intr = 0;

	iov.iov_base = buf;
	while (1) {
		int status;
		const struct rtnl_dump_filter_arg *a;
		int found_done = 0;
		int msglen = 0;

		iov.iov_len = sizeof(buf);
		status = recvmsg(rth->fd, &msg, 0);

		if (status < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			fprintf(stderr, "netlink receive error %s (%d)\n",
				strerror(errno), errno);
			return -1;
		}

		if (status == 0) {
			fprintf(stderr, "EOF on netlink\n");
			return -1;
		}

		if (rth->dump_fp)
			fwrite(buf, 1, NLMSG_ALIGN(status), rth->dump_fp);

		for (a = arg; a->filter; a++) {
			struct nlmsghdr *h = (struct nlmsghdr *)buf;

			msglen = status;

			while (NLMSG_OK(h, msglen)) {
				int err = 0;

				h->nlmsg_flags &= ~a->nc_flags;

				if (nladdr.nl_pid != 0 ||
				    h->nlmsg_pid != rth->local.nl_pid ||
				    h->nlmsg_seq != rth->dump)
					goto skip_it;

				if (h->nlmsg_flags & NLM_F_DUMP_INTR)
					dump_intr = 1;

				if (h->nlmsg_type == NLMSG_DONE) {
					err = rtnl_dump_done(rth, h);
					if (err < 0)
						return -1;

					found_done = 1;
					break; /* process next filter */
				}

				if (h->nlmsg_type == NLMSG_ERROR) {
					rtnl_dump_error(rth, h);
					return -1;
				}

				if (!rth->dump_fp) {
					err = a->filter(&nladdr, h, a->arg1);
					if (err < 0)
						return err;
				}

skip_it:
				h = NLMSG_NEXT(h, msglen);
			}
		}

		if (found_done) {
			if (dump_intr)
				fprintf(stderr,
					"Dump was interrupted and may be inconsistent.\n");
			return 0;
		}

		if (msg.msg_flags & MSG_TRUNC) {
			fprintf(stderr, "Message truncated\n");
			continue;
		}
		if (msglen) {
			fprintf(stderr, "!!!Remnant of size %d\n", msglen);
			exit(1);
		}
	}
}

int rtnl_dump_filter_nc(struct rtnl_handle *rth,
		     rtnl_filter_t filter,
		     void *arg1, __u16 nc_flags)
{
	const struct rtnl_dump_filter_arg a[2] = {
		{ .filter = filter, .arg1 = arg1, .nc_flags = nc_flags, },
		{ .filter = NULL,   .arg1 = NULL, .nc_flags = 0, },
	};

	return rtnl_dump_filter_l(rth, a);
}

static int __rtnl_talk(struct rtnl_handle *rtnl, struct nlmsghdr *n,
		       struct nlmsghdr *answer, size_t maxlen,
		       bool show_rtnl_err)
{
	int status;
	unsigned int seq;
	struct nlmsghdr *h;
	struct sockaddr_nl nladdr = { .nl_family = AF_NETLINK };
	struct iovec iov = {
		.iov_base = n,
		.iov_len = n->nlmsg_len
	};
	struct msghdr msg = {
		.msg_name = &nladdr,
		.msg_namelen = sizeof(nladdr),
		.msg_iov = &iov,
		.msg_iovlen = 1,
	};
	char   buf[32768] = {};

	n->nlmsg_seq = seq = ++rtnl->seq;

	if (answer == NULL)
		n->nlmsg_flags |= NLM_F_ACK;

	status = sendmsg(rtnl->fd, &msg, 0);
	if (status < 0) {
		perror("Cannot talk to rtnetlink");
		return -1;
	}

	iov.iov_base = buf;
	while (1) {
		iov.iov_len = sizeof(buf);
		status = recvmsg(rtnl->fd, &msg, 0);

		if (status < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			fprintf(stderr, "netlink receive error %s (%d)\n",
				strerror(errno), errno);
			return -1;
		}
		if (status == 0) {
			fprintf(stderr, "EOF on netlink\n");
			return -1;
		}
		if (msg.msg_namelen != sizeof(nladdr)) {
			fprintf(stderr,
				"sender address length == %d\n",
				msg.msg_namelen);
			exit(1);
		}
		for (h = (struct nlmsghdr *)buf; status >= sizeof(*h); ) {
			int len = h->nlmsg_len;
			int l = len - sizeof(*h);

			if (l < 0 || len > status) {
				if (msg.msg_flags & MSG_TRUNC) {
					fprintf(stderr, "Truncated message\n");
					return -1;
				}
				fprintf(stderr,
					"!!!malformed message: len=%d\n",
					len);
				exit(1);
			}

			if (nladdr.nl_pid != 0 ||
			    h->nlmsg_pid != rtnl->local.nl_pid ||
			    h->nlmsg_seq != seq) {
				/* Don't forget to skip that message. */
				status -= NLMSG_ALIGN(len);
				h = (struct nlmsghdr *)((char *)h + NLMSG_ALIGN(len));
				continue;
			}

			if (h->nlmsg_type == NLMSG_ERROR) {
				struct nlmsgerr *err = (struct nlmsgerr *)NLMSG_DATA(h);

				if (l < sizeof(struct nlmsgerr)) {
					fprintf(stderr, "ERROR truncated\n");
				} else if (!err->error) {
					if (answer)
						memcpy(answer, h,
						       MIN(maxlen, h->nlmsg_len));
					return 0;
				}

				if (rtnl->proto != NETLINK_SOCK_DIAG && show_rtnl_err)
					fprintf(stderr,
						"RTNETLINK answers: %s\n",
						strerror(-err->error));
				errno = -err->error;
				return -1;
			}

			if (answer) {
				memcpy(answer, h,
				       MIN(maxlen, h->nlmsg_len));
				return 0;
			}

			fprintf(stderr, "Unexpected reply!!!\n");

			status -= NLMSG_ALIGN(len);
			h = (struct nlmsghdr *)((char *)h + NLMSG_ALIGN(len));
		}

		if (msg.msg_flags & MSG_TRUNC) {
			fprintf(stderr, "Message truncated\n");
			continue;
		}

		if (status) {
			fprintf(stderr, "!!!Remnant of size %d\n", status);
			exit(1);
		}
	}
}

int rtnl_talk(struct rtnl_handle *rtnl, struct nlmsghdr *n,
	      struct nlmsghdr *answer, size_t maxlen)
{
	return __rtnl_talk(rtnl, n, answer, maxlen, true);
}

int rtnl_talk_suppress_rtnl_errmsg(struct rtnl_handle *rtnl, struct nlmsghdr *n,
				   struct nlmsghdr *answer, size_t maxlen)
{
	return __rtnl_talk(rtnl, n, answer, maxlen, false);
}

int rtnl_listen_all_nsid(struct rtnl_handle *rth)
{
	unsigned int on = 1;

	if (setsockopt(rth->fd, SOL_NETLINK, NETLINK_LISTEN_ALL_NSID, &on,
		       sizeof(on)) < 0) {
		perror("NETLINK_LISTEN_ALL_NSID");
		return -1;
	}
	rth->flags |= RTNL_HANDLE_F_LISTEN_ALL_NSID;
	return 0;
}

int rtnl_listen(struct rtnl_handle *rtnl,
		rtnl_listen_filter_t handler,
		void *jarg)
{
	int status;
	struct nlmsghdr *h;
	struct sockaddr_nl nladdr = { .nl_family = AF_NETLINK };
	struct iovec iov;
	struct msghdr msg = {
		.msg_name = &nladdr,
		.msg_namelen = sizeof(nladdr),
		.msg_iov = &iov,
		.msg_iovlen = 1,
	};
	char   buf[16384];
	char   cmsgbuf[BUFSIZ];

	if (rtnl->flags & RTNL_HANDLE_F_LISTEN_ALL_NSID) {
		msg.msg_control = &cmsgbuf;
		msg.msg_controllen = sizeof(cmsgbuf);
	}

	iov.iov_base = buf;
	while (1) {
		struct rtnl_ctrl_data ctrl;
		struct cmsghdr *cmsg;

		iov.iov_len = sizeof(buf);
		status = recvmsg(rtnl->fd, &msg, 0);

		if (status < 0) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			fprintf(stderr, "netlink receive error %s (%d)\n",
				strerror(errno), errno);
			if (errno == ENOBUFS)
				continue;
			return -1;
		}
		if (status == 0) {
			fprintf(stderr, "EOF on netlink\n");
			return -1;
		}
		if (msg.msg_namelen != sizeof(nladdr)) {
			fprintf(stderr,
				"Sender address length == %d\n",
				msg.msg_namelen);
			exit(1);
		}

		if (rtnl->flags & RTNL_HANDLE_F_LISTEN_ALL_NSID) {
			memset(&ctrl, 0, sizeof(ctrl));
			ctrl.nsid = -1;
			for (cmsg = CMSG_FIRSTHDR(&msg); cmsg;
			     cmsg = CMSG_NXTHDR(&msg, cmsg))
				if (cmsg->cmsg_level == SOL_NETLINK &&
				    cmsg->cmsg_type == NETLINK_LISTEN_ALL_NSID &&
				    cmsg->cmsg_len == CMSG_LEN(sizeof(int))) {
					int *data = (int *)CMSG_DATA(cmsg);

					ctrl.nsid = *data;
				}
		}

		for (h = (struct nlmsghdr *)buf; status >= sizeof(*h); ) {
			int err;
			int len = h->nlmsg_len;
			int l = len - sizeof(*h);

			if (l < 0 || len > status) {
				if (msg.msg_flags & MSG_TRUNC) {
					fprintf(stderr, "Truncated message\n");
					return -1;
				}
				fprintf(stderr,
					"!!!malformed message: len=%d\n",
					len);
				exit(1);
			}

			err = handler(&nladdr, &ctrl, h, jarg);
			if (err < 0)
				return err;

			status -= NLMSG_ALIGN(len);
			h = (struct nlmsghdr *)((char *)h + NLMSG_ALIGN(len));
		}
		if (msg.msg_flags & MSG_TRUNC) {
			fprintf(stderr, "Message truncated\n");
			continue;
		}
		if (status) {
			fprintf(stderr, "!!!Remnant of size %d\n", status);
			exit(1);
		}
	}
}

int rtnl_from_file(FILE *rtnl, rtnl_listen_filter_t handler,
		   void *jarg)
{
	int status;
	struct sockaddr_nl nladdr = { .nl_family = AF_NETLINK };
	char buf[16384];
	struct nlmsghdr *h = (struct nlmsghdr *)buf;

	while (1) {
		int err, len;
		int l;

		status = fread(&buf, 1, sizeof(*h), rtnl);

		if (status < 0) {
			if (errno == EINTR)
				continue;
			perror("rtnl_from_file: fread");
			return -1;
		}
		if (status == 0)
			return 0;

		len = h->nlmsg_len;
		l = len - sizeof(*h);

		if (l < 0 || len > sizeof(buf)) {
			fprintf(stderr, "!!!malformed message: len=%d @%lu\n",
				len, ftell(rtnl));
			return -1;
		}

		status = fread(NLMSG_DATA(h), 1, NLMSG_ALIGN(l), rtnl);

		if (status < 0) {
			perror("rtnl_from_file: fread");
			return -1;
		}
		if (status < l) {
			fprintf(stderr, "rtnl-from_file: truncated message\n");
			return -1;
		}

		err = handler(&nladdr, NULL, h, jarg);
		if (err < 0)
			return err;
	}
}

int addattr(struct nlmsghdr *n, int maxlen, int type)
{
	return addattr_l(n, maxlen, type, NULL, 0);
}

int addattr8(struct nlmsghdr *n, int maxlen, int type, __u8 data)
{
	return addattr_l(n, maxlen, type, &data, sizeof(__u8));
}

int addattr16(struct nlmsghdr *n, int maxlen, int type, __u16 data)
{
	return addattr_l(n, maxlen, type, &data, sizeof(__u16));
}

int addattr32(struct nlmsghdr *n, int maxlen, int type, __u32 data)
{
	return addattr_l(n, maxlen, type, &data, sizeof(__u32));
}

int addattr64(struct nlmsghdr *n, int maxlen, int type, __u64 data)
{
	return addattr_l(n, maxlen, type, &data, sizeof(__u64));
}

int addattrstrz(struct nlmsghdr *n, int maxlen, int type, const char *str)
{
	return addattr_l(n, maxlen, type, str, strlen(str)+1);
}

int addattr_l(struct nlmsghdr *n, int maxlen, int type, const void *data,
	      int alen)
{
	int len = RTA_LENGTH(alen);
	struct rtattr *rta;

	if (NLMSG_ALIGN(n->nlmsg_len) + RTA_ALIGN(len) > maxlen) {
		fprintf(stderr,
			"addattr_l ERROR: message exceeded bound of %d\n",
			maxlen);
		return -1;
	}
	rta = NLMSG_TAIL(n);
	rta->rta_type = type;
	rta->rta_len = len;
	memcpy(RTA_DATA(rta), data, alen);
	n->nlmsg_len = NLMSG_ALIGN(n->nlmsg_len) + RTA_ALIGN(len);
	return 0;
}

int addraw_l(struct nlmsghdr *n, int maxlen, const void *data, int len)
{
	if (NLMSG_ALIGN(n->nlmsg_len) + NLMSG_ALIGN(len) > maxlen) {
		fprintf(stderr,
			"addraw_l ERROR: message exceeded bound of %d\n",
			maxlen);
		return -1;
	}

	memcpy(NLMSG_TAIL(n), data, len);
	memset((void *) NLMSG_TAIL(n) + len, 0, NLMSG_ALIGN(len) - len);
	n->nlmsg_len = NLMSG_ALIGN(n->nlmsg_len) + NLMSG_ALIGN(len);
	return 0;
}

struct rtattr *addattr_nest(struct nlmsghdr *n, int maxlen, int type)
{
	struct rtattr *nest = NLMSG_TAIL(n);

	addattr_l(n, maxlen, type, NULL, 0);
	return nest;
}

int addattr_nest_end(struct nlmsghdr *n, struct rtattr *nest)
{
	nest->rta_len = (void *)NLMSG_TAIL(n) - (void *)nest;
	return n->nlmsg_len;
}

struct rtattr *addattr_nest_compat(struct nlmsghdr *n, int maxlen, int type,
				   const void *data, int len)
{
	struct rtattr *start = NLMSG_TAIL(n);

	addattr_l(n, maxlen, type, data, len);
	addattr_nest(n, maxlen, type);
	return start;
}

int addattr_nest_compat_end(struct nlmsghdr *n, struct rtattr *start)
{
	struct rtattr *nest = (void *)start + NLMSG_ALIGN(start->rta_len);

	start->rta_len = (void *)NLMSG_TAIL(n) - (void *)start;
	addattr_nest_end(n, nest);
	return n->nlmsg_len;
}

int rta_addattr32(struct rtattr *rta, int maxlen, int type, __u32 data)
{
	int len = RTA_LENGTH(4);
	struct rtattr *subrta;

	if (RTA_ALIGN(rta->rta_len) + len > maxlen) {
		fprintf(stderr,
			"rta_addattr32: Error! max allowed bound %d exceeded\n",
			maxlen);
		return -1;
	}
	subrta = (struct rtattr *)(((char *)rta) + RTA_ALIGN(rta->rta_len));
	subrta->rta_type = type;
	subrta->rta_len = len;
	memcpy(RTA_DATA(subrta), &data, 4);
	rta->rta_len = NLMSG_ALIGN(rta->rta_len) + len;
	return 0;
}

int rta_addattr_l(struct rtattr *rta, int maxlen, int type,
		  const void *data, int alen)
{
	struct rtattr *subrta;
	int len = RTA_LENGTH(alen);

	if (RTA_ALIGN(rta->rta_len) + RTA_ALIGN(len) > maxlen) {
		fprintf(stderr,
			"rta_addattr_l: Error! max allowed bound %d exceeded\n",
			maxlen);
		return -1;
	}
	subrta = (struct rtattr *)(((char *)rta) + RTA_ALIGN(rta->rta_len));
	subrta->rta_type = type;
	subrta->rta_len = len;
	memcpy(RTA_DATA(subrta), data, alen);
	rta->rta_len = NLMSG_ALIGN(rta->rta_len) + RTA_ALIGN(len);
	return 0;
}

int rta_addattr8(struct rtattr *rta, int maxlen, int type, __u8 data)
{
	return rta_addattr_l(rta, maxlen, type, &data, sizeof(__u8));
}

int rta_addattr16(struct rtattr *rta, int maxlen, int type, __u16 data)
{
	return rta_addattr_l(rta, maxlen, type, &data, sizeof(__u16));
}

int rta_addattr64(struct rtattr *rta, int maxlen, int type, __u64 data)
{
	return rta_addattr_l(rta, maxlen, type, &data, sizeof(__u64));
}

struct rtattr *rta_nest(struct rtattr *rta, int maxlen, int type)
{
	struct rtattr *nest = RTA_TAIL(rta);

	rta_addattr_l(rta, maxlen, type, NULL, 0);

	return nest;
}

int rta_nest_end(struct rtattr *rta, struct rtattr *nest)
{
	nest->rta_len = (void *)RTA_TAIL(rta) - (void *)nest;

	return rta->rta_len;
}

int parse_rtattr(struct rtattr *tb[], int max, struct rtattr *rta, int len)
{
	return parse_rtattr_flags(tb, max, rta, len, 0);
}

int parse_rtattr_flags(struct rtattr *tb[], int max, struct rtattr *rta,
		       int len, unsigned short flags)
{
	unsigned short type;

	memset(tb, 0, sizeof(struct rtattr *) * (max + 1));
	while (RTA_OK(rta, len)) {
		type = rta->rta_type & ~flags;
		if ((type <= max) && (!tb[type]))
			tb[type] = rta;
		rta = RTA_NEXT(rta, len);
	}
	if (len)
		fprintf(stderr, "!!!Deficit %d, rta_len=%d\n",
			len, rta->rta_len);
	return 0;
}

int parse_rtattr_byindex(struct rtattr *tb[], int max,
			 struct rtattr *rta, int len)
{
	int i = 0;

	memset(tb, 0, sizeof(struct rtattr *) * max);
	while (RTA_OK(rta, len)) {
		if (rta->rta_type <= max && i < max)
			tb[i++] = rta;
		rta = RTA_NEXT(rta, len);
	}
	if (len)
		fprintf(stderr, "!!!Deficit %d, rta_len=%d\n",
			len, rta->rta_len);
	return i;
}

struct rtattr *parse_rtattr_one(int type, struct rtattr *rta, int len)
{
	while (RTA_OK(rta, len)) {
		if (rta->rta_type == type)
			return rta;
		rta = RTA_NEXT(rta, len);
	}

	if (len)
		fprintf(stderr, "!!!Deficit %d, rta_len=%d\n",
			len, rta->rta_len);
	return NULL;
}

int __parse_rtattr_nested_compat(struct rtattr *tb[], int max,
				 struct rtattr *rta,
				 int len)
{
	if (RTA_PAYLOAD(rta) < len)
		return -1;
	if (RTA_PAYLOAD(rta) >= RTA_ALIGN(len) + sizeof(struct rtattr)) {
		rta = RTA_DATA(rta) + RTA_ALIGN(len);
		return parse_rtattr_nested(tb, max, rta);
	}
	memset(tb, 0, sizeof(struct rtattr *) * (max + 1));
	return 0;
}
