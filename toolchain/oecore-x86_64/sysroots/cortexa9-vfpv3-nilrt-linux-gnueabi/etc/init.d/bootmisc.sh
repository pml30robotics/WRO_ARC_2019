#!/bin/sh
### BEGIN INIT INFO
# Provides:          bootmisc
# Required-Start:    $local_fs mountvirtfs
# Required-Stop:     $local_fs
# Default-Start:     S
# Default-Stop:      0 6
# Short-Description: Misc and other.
### END INIT INFO

. /etc/default/rcS
#
# Put a nologin file in /etc to prevent people from logging in before
# system startup is complete.
#
if test "$DELAYLOGIN" = yes
then
  echo "System bootup in progress - please wait" > /etc/nologin
  cp /etc/nologin /etc/nologin.boot
fi

#
# Set pseudo-terminal access permissions.
#
if test -c /dev/ttyp0
then
	chmod 666 /dev/tty[p-za-e][0-9a-f]
	chown root:tty /dev/tty[p-za-e][0-9a-f]
fi

#
# Apply /proc settings if defined
#
SYSCTL_CONF="/etc/sysctl.conf"
if [ -f "${SYSCTL_CONF}" ]
then
	if [ -x "/sbin/sysctl" ]
	then
		# busybox sysctl does not support -q
		VERBOSE_REDIR="1>/dev/null"
		if [ "${VERBOSE}" != "no" ]; then
			VERBOSE_REDIR="1>&1"
		fi
		eval /sbin/sysctl -p "${SYSCTL_CONF}" $VERBOSE_REDIR
	else
		echo "To have ${SYSCTL_CONF} applied during boot, install package <procps>."
	fi
fi

#
# Update /etc/motd.
#
if test "$EDITMOTD" != no
then
	uname -a > /etc/motd.tmp
	sed 1d /etc/motd >> /etc/motd.tmp
	mv /etc/motd.tmp /etc/motd
fi

#
# This is as good a place as any for a sanity check
#
# /tmp should be a symlink to /var/tmp to cut down on the number of mounted
# ramdisks.
if test ! -L /tmp && test -d /var/tmp
then
	rm -rf /tmp
	ln -sf /var/tmp /tmp
fi

# Update lib cache if config is present
# Do it twice because ni libs don't follow normal UNIX name conventions.
if [ -e /etc/ld.so.conf ] ; then
	/sbin/ldconfig
	/sbin/ldconfig
fi

# Set the system clock from hardware clock, if it is available.
if test -x /etc/init.d/hwclock.sh && hwclock --show >/dev/null; then
	/etc/init.d/hwclock.sh start && exit 0
fi

# Otherwise, if the timestamp is more recent than the current time, use the
# timestamp instead.
if test -e /etc/timestamp
then
	SYSTEMDATE=`date -u +%4Y%2m%2d%2H%2M%2S`
	read TIMESTAMP < /etc/timestamp
	if [ ${TIMESTAMP} -gt $SYSTEMDATE ]; then
		# format the timestamp as date expects it (2m2d2H2M4Y.2S)
		TS_YR=${TIMESTAMP%??????????}
		TS_SEC=${TIMESTAMP#????????????}
		TS_FIRST12=${TIMESTAMP%??}
		TS_MIDDLE8=${TS_FIRST12#????}
		date -u ${TS_MIDDLE8}${TS_YR}.${TS_SEC}
		test -x /etc/init.d/hwclock.sh && /etc/init.d/hwclock.sh stop
	fi
fi
: exit 0
