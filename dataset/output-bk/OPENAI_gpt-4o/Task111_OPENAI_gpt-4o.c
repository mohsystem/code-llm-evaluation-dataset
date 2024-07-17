#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <stdio.h>

static xmlrpc_value * add_method(xmlrpc_env * const env, xmlrpc_value * const param_array, void * const user_data) {
    xmlrpc_int32 x, y, result;
    
    xmlrpc_decompose_value(env, param_array, "(ii)", &x, &y);
    if (env->fault_occurred)
        return NULL;

    result = x + y;

    return xmlrpc_build_value(env, "i", result);
}

int main() {
    xmlrpc_env env;
    xmlrpc_server_abyss_parms serverparms;
    xmlrpc_registry * registry;

    xmlrpc_env_init(&env);
    registry = xmlrpc_registry_new(&env);
    
    xmlrpc_registry_add_method(&env, registry, NULL, "sample.add", &add_method, NULL);

    serverparms.config_file_name = NULL;
    serverparms.registryP = registry;
    serverparms.port_number = 8081;

    printf("C XML-RPC server running on port 8081...
");
    xmlrpc_server_abyss(&env, &serverparms, XMLRPC_APSIZE(port_number));
    return 0;
}