
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class AddMethod : public xmlrpc_c::method {
public:
    void execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
        int const x(paramList.getInt(0));
        int const y(paramList.getInt(1));
        *retvalP = xmlrpc_c::value_int(x + y);
    }
};

class SubtractMethod : public xmlrpc_c::method {
public:
    void execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value* const retvalP) {
        int const x(paramList.getInt(0));
        int const y(paramList.getInt(1));
        *retvalP = xmlrpc_c::value_int(x - y);
    }
};

int main() {
    xmlrpc_c::registry myRegistry;
    xmlrpc_c::methodPtr const addMethodP(new AddMethod);
    xmlrpc_c::methodPtr const subtractMethodP(new SubtractMethod);

    myRegistry.addMethod("add", addMethodP);
    myRegistry.addMethod("subtract", subtractMethodP);

    xmlrpc_c::serverAbyss myAbyssServer(xmlrpc_c::serverAbyss::constrOpt()
        .registryP(&myRegistry)
        .port(8000));

    std::cout << "XML-RPC server is running on port 8000..." << std::endl;
    myAbyssServer.run();

    return 0;
}
