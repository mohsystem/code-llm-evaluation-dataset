#include <xmlrpc-c/server.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/registry.h>

static xmlrpc_value *
sample_add(xmlrpc_env *   const envP, 
           xmlrpc_value * const paramArrayP,
           void *         const user_data ATTR_UNUSED) {

    xmlrpc_int32 x, y, z;

    /* Parse our arguments out of the passed array */
    xmlrpc_decompose_value(envP, paramArrayP, "(ii)", &x, &y);
    if (envP->fault_occurred)
        return xmlrpc_build_fault_value(envP,
                                        "Parameter parsing failed: %s",
                                        envP->fault_string);

    /* Add our two numbers */
    z = x + y;

    /* Return our result */
    return xmlrpc_build_value(envP, "i", z);
}



int 
main(int          const argc, 
     const char ** const argv) {

    xmlrpc_env env;
    xmlrpc_registry * registryP;
    xmlrpc_server * serverP;

    xmlrpc_env_init(&env);

    registryP = xmlrpc_registry_new(&env);

    xmlrpc_registry_add_method(
        &env, registryP, NULL, "sample.add", &sample_add, NULL);

    serverP = xmlrpc_server_create(&env, "XmlRpc-C Server", 8080, &env);
    if (env.fault_occurred) {
        fprintf(stderr, "Failed to create server: %s
", env.fault_string);
        return 1;
    }

    xmlrpc_server_register_introspection_data(&env, serverP, registryP);

    xmlrpc_server_run_server(serverP, &env);

    xmlrpc_server_destroy(serverP);
    xmlrpc_registry_free(registryP);
    xmlrpc_env_clean(&env);

    return 0;
}