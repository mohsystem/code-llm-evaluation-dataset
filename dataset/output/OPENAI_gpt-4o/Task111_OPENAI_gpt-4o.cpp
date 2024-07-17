#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#include <iostream>

class SampleAddMethod : public xmlrpc_c::method {
public:
    SampleAddMethod() {
        this->_signature = "i:ii";
        this->_help = "This method adds two integers";
    }
    void execute(xmlrpc_c::paramList const & paramList, xmlrpc_c::value * const retval) {
        int x = paramList.getInt(0);
        int y = paramList.getInt(1);
        int result = x + y;
        *retval = xmlrpc_c::value_int(result);
    }
};

int main() {
    try {
        xmlrpc_c::registry myRegistry;
        xmlrpc_c::methodPtr const sampleAddMethodP(new SampleAddMethod);
        myRegistry.addMethod("sample.add", sampleAddMethodP);
        xmlrpc_c::serverAbyss myAbyssServer(xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(8082));
        std::cout << "C++ XML-RPC server running on port 8082..." << std::endl;
        myAbyssServer.run();
    } catch (std::exception const & e) {
        std::cerr << "Something failed. " << e.what() << std::endl;
    }
    return 0;
}