// C does not have built-in XML-RPC server, you need to use a third-party library like libxmlrpc.
// Here is a simple example using libxmlrpc:

#include <stdio.h>
#include <stdlib.h>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/server.h>
#include <xmlrpc-c/server_abyss.h>

xmlrpc_value* add(xmlrpc_env* const envP, xmlrpc_value* const paramArrayP, void* const serverInfo, void* const userData) {
    int sum = 0;
    int i;
    for (i = 0; i < xmlrpc_array_size(envP, paramArrayP); i++) {
        xmlrpc_value* valueP;
        xmlrpc_array_read_item(envP, paramArrayP, i, &valueP);
        xmlrpc_int32 value;
        xmlrpc_read_int(envP, valueP, &value);
        sum += value;
    }
    return xmlrpc_build_value(envP, "i", sum);
}

int main() {
    xmlrpc_server* serverP;
    xmlrpc_server_abyss_parms serverparm;
    xmlrpc_registry* registryP;
    xmlrpc_env env;

    xmlrpc_env_init(&env);
    serverP = xmlrpc_server_abyss_new(&env, XMLRPC_SERVER_ABYSS_FLAGS_NONE, "localhost", 8000, NULL, 0);
    if (serverP == NULL) {
        fprintf(stderr, "xmlrpc_server_abyss_new() failed.  Error code is %d\n", env.fault_occurred);
        return 1;
    }

    registryP = xmlrpc_registry_new(&env);
    if (registryP == NULL) {
        fprintf(stderr, "xmlrpc_registry_new() failed.  Error code is %d\n", env.fault_occurred);
        return 1;
    }

    xmlrpc_registry_add_method(&env, registryP, NULL, "add", add, NULL);
    if (env.fault_occurred) {
        fprintf(stderr, "xmlrpc_registry_add_method() failed.  Error code is %d\n", env.fault_occurred);
        return 1;
    }

    serverparm.registryP = registryP;
    serverparm.config_file_name = NULL;
    serverparm.flags = XMLRPC_SERVER_ABYSS_FLAGS_NONE;

    if (!xmlrpc_server_abyss(serverP, &serverparm, XMLRPC_APSIZE(serverparm))) {
        fprintf(stderr, "xmlrpc_server_abyss() failed.  Error code is %d\n", env.fault_occurred);
        return 1;
    }

    return 0;
}