// C
// This is a simplified example using libxmlrpc.
// A real-world application would require more complex error handling and memory management.
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_abyss.h>

static xmlrpc_value *
method_sample(xmlrpc_env * const envP,
              xmlrpc_value * const paramArrayP,
              void * const serverInfo,
              void * const channelInfo) {
    xmlrpc_value * resultP;
    xmlrpc_value * paramP;
    char * param;

    paramP = xmlrpc_array_elt(paramArrayP, 0);
    param = xmlrpc_get_string(envP, paramP);

    resultP = xmlrpc_build_value(envP, "{s:s}", "result", xmlrpc_string_new(envP, param));
    free(param);

    return resultP;
}

int main(void) {
    xmlrpc_server * serverP;
    xmlrpc_registry * registryP;
    xmlrpc_env env;

    xmlrpc_env_init(&env);
    serverP = xmlrpc_server_abyss_new(&env, 8080, NULL, NULL);
    registryP = xmlrpc_registry_new(&env);
    xmlrpc_registry_add_method(&env, registryP, NULL, "sample", method_sample, NULL);
    xmlrpc_server_set_registry(serverP, registryP, NULL);
    xmlrpc_server_run(serverP);

    xmlrpc_server_destroy(serverP);
    xmlrpc_registry_free(registryP);
    xmlrpc_env_clean(&env);

    return 0;
}