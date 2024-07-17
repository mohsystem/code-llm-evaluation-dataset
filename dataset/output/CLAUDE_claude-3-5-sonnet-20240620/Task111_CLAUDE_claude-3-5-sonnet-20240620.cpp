
#include <iostream>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class AddMethod : public xmlrpc_c::method {
public:
    AddMethod() {
        this->_signature = "i:ii";
        this->_help = "This method adds two integers.";
    }

    void execute(xmlrpc_c::paramList const& paramList,
                 xmlrpc_c::value* const retvalP) {
        int const x(paramList.getInt(0));
        int const y(paramList.getInt(1));

        *retvalP = xmlrpc_c::value_int(x + y);
    }
};

int main() {
    try {
        xmlrpc_c::registry myRegistry;
        xmlrpc_c::methodPtr const addMethodP(new AddMethod);
        myRegistry.addMethod("add", addMethodP);

        xmlrpc_c::serverAbyss myAbyssServer(
            xmlrpc_c::serverAbyss::constrOpt()
            .registryP(&myRegistry)
            .port(8080)
        );

        std::cout << "XML-RPC server running on port 8080..." << std::endl;
        myAbyssServer.run();
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
