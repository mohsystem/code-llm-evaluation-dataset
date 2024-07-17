
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_abyss.h>

static xmlrpc_value *
add(xmlrpc_env *env, xmlrpc_value *param_array, void *user_data) {
    int x, y, z;

    xmlrpc_decompose_value(env, param_array, "(ii)", &x, &y);
    if (env->fault_occurred)
        return NULL;

    z = x + y;

    return xmlrpc_build_value(env, "i", z);
}

int main(int argc, char **argv) {
    struct xmlrpc_method_info3 const add_method = {
        "add",
        add,
        NULL,
        0,
        "i:ii",
        "Add two integers."
    };

    xmlrpc_server_abyss_parms serverparm;
    xmlrpc_registry *registryP;
    xmlrpc_env env;

    xmlrpc_env_init(&env);

    registryP = xmlrpc_registry_new(&env);
    if (env.fault_occurred) {
        fprintf(stderr, "xmlrpc_registry_new() failed: %s\
", env.fault_string);
        exit(1);
    }

    xmlrpc_registry_add_method3(&env, registryP, &add_method);
    if (env.fault_occurred) {
        fprintf(stderr, "xmlrpc_registry_add_method3() failed: %s\
", env.fault_string);
        exit(1);
    }

    serverparm.config_file_name = NULL;
    serverparm.registryP = registryP;
    serverparm.port_number = 8080;

    printf("XML-RPC server running on port %d...\
", serverparm.port_number);
    xmlrpc_server_abyss(&env, &serverparm, XMLRPC_APSIZE(port_number));

    return 0;
}
