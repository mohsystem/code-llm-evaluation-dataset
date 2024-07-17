#include <xmlrpc-c/xmlrpc.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/registry.h>

int add(xmlrpc_env *env, xmlrpc_value *paramArray, xmlrpc_value **result) {
    int a, b;
    xmlrpc_int2(xmlrpc_array_get_int(env, param, 0, &a));
    xmlrpc_int2(xmlrpc_array_get_int(env, param, 1, &b));
    xmlrpc_int2(xmlrpc_value_int(env, a + b, result));
    return 1;
}

int echo(xmlrpc_env *env, xmlrpc_value *param, xmlrpc_value **result) {
    xmlrpc_string *str;
    xmlrpc_string_get_value(env, param, &str);
    xmlrpc_string_new(env, str, result);
    return 1;
}

int main() {
    xmlrpc_env env;
    xmlrpc_env_init(&env);
    xmlrpc_registry *registryP;
    xmlrpc_registry_new(&registryP);
    xmlrpc_registry_add_method(&env, registryP, "add", "{ii:i}", add);
    xmlrpc_registry_add_method(&env, registryP, "echo", "{s:s}", echo);
    xmlrpc_server_abyss_setup(&env, registryP, 8080);
    xmlrpc_env_clean(&env);
    return 0;
}