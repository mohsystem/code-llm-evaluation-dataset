#include <iostream>
#include <string>
#include <xmlrpc-c/base.h>
#include <xmlrpc-c/registry.h>
#include <xmlrpc-c/server_abyss.h>

using namespace std;

class MyMethods {
public:
    // Method to add two numbers
    xmlrpc_value* add(xmlrpc_env* const env, xmlrpc_value* const param_array,
                      void* const user_data) {
        int const a = xmlrpc_read_int(env, xmlrpc_array_get_item(param_array, 0));
        int const b = xmlrpc_read_int(env, xmlrpc_array_get_item(param_array, 1));

        if (env->fault_occurred)
            return xmlrpc_build_fault(env, 1, "Invalid parameters.");

        int sum = a + b;
        return xmlrpc_build_value(env, "i", sum);
    }

    // Method to subtract two numbers
    xmlrpc_value* subtract(xmlrpc_env* const env, xmlrpc_value* const param_array,
                         void* const user_data) {
        int const a = xmlrpc_read_int(env, xmlrpc_array_get_item(param_array, 0));
        int const b = xmlrpc_read_int(env, xmlrpc_array_get_item(param_array, 1));

        if (env->fault_occurred)
            return xmlrpc_build_fault(env, 1, "Invalid parameters.");

        int difference = a - b;
        return xmlrpc_build_value(env, "i", difference);
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <port>" << endl;
        return 1;
    }

    int port = atoi(argv[1]);

    try {
        xmlrpc_server_abyss_parms serverparm;
        xmlrpc_registry* registryP;
        xmlrpc_env env;

        xmlrpc_env_init(&env);
        registryP = xmlrpc_registry_new(&env);

        MyMethods myMethods;
        xmlrpc_method_info3 const methodInfo_add = {
                "sample.add",
                &MyMethods::add,
                NULL
        };
        xmlrpc_method_info3 const methodInfo_subtract = {
                "sample.subtract",
                &MyMethods::subtract,
                NULL
        };
        xmlrpc_registry_add_method3(&env, registryP, NULL, "sample",
                                    &methodInfo_add, &myMethods);
        xmlrpc_registry_add_method3(&env, registryP, NULL, "sample",
                                    &methodInfo_subtract, &myMethods);

        serverparm.config_file_name = NULL;
        serverparm.registryP = registryP;
        serverparm.port_number = port;
        serverparm.log_file_name = NULL;

        xmlrpc_server_abyss(&env, &serverparm, XMLRPC_APSIZE(log_file_name));

        if (env.fault_occurred) {
            cerr << "XML-RPC server failed to start: " << env.fault_string << endl;
            return 1;
        }

        cout << "XML-RPC server listening on port " << port << endl;
        cout << "Press Ctrl+C to exit." << endl;

        // Keep the server running
        while (true) {
            sleep(1);
        }

        xmlrpc_registry_free(registryP);
        xmlrpc_env_clean(&env);

    } catch (exception const& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}