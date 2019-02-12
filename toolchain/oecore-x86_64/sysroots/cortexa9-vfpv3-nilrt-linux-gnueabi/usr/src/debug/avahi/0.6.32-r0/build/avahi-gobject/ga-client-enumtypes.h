


#ifndef __GA_CLIENT_ENUM_TYPES_H__
#define __GA_CLIENT_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS
/* enumerations from "../../avahi-0.6.32/avahi-gobject/ga-client.h" */
GType ga_client_state_get_type (void);
#define GA_TYPE_CLIENT_STATE (ga_client_state_get_type())
GType ga_client_flags_get_type (void);
#define GA_TYPE_CLIENT_FLAGS (ga_client_flags_get_type())
G_END_DECLS

#endif /* __GA_CLIENT_ENUM_TYPES_H__ */



