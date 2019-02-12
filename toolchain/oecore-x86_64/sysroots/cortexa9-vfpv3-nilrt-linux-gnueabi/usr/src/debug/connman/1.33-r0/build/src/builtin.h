extern struct connman_plugin_desc __connman_builtin_loopback;
extern struct connman_plugin_desc __connman_builtin_ethernet;
extern struct connman_plugin_desc __connman_builtin_gadget;
extern struct connman_plugin_desc __connman_builtin_wifi;
extern struct connman_plugin_desc __connman_builtin_bluetooth;
extern struct connman_plugin_desc __connman_builtin_dundee;
extern struct connman_plugin_desc __connman_builtin_pacrunner;
extern struct connman_plugin_desc __connman_builtin_neard;

static struct connman_plugin_desc *__connman_builtin[] = {
  &__connman_builtin_loopback,
  &__connman_builtin_ethernet,
  &__connman_builtin_gadget,
  &__connman_builtin_wifi,
  &__connman_builtin_bluetooth,
  &__connman_builtin_dundee,
  &__connman_builtin_pacrunner,
  &__connman_builtin_neard,
  NULL
};
