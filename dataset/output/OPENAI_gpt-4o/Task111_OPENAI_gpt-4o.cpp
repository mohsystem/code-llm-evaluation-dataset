#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class addMethod : public xmlrpc_c::method {
public:
    void execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value*   const  retvalP) {
        int const x(paramList.getInt(0));
        int const y(paramList.getInt(1));
        paramList.verifyEnd(2);
        *retvalP = xmlrpc_c::value_int(x + y);
    }
};

class subtractMethod : public xmlrpc_c::method {
public:
    void execute(xmlrpc_c::paramList const& paramList, xmlrpc_c::value*   const  retvalP) {
        int const x(paramList.getInt(0));
        int const y(paramList.getInt(1));
        paramList.verifyEnd(2);
        *retvalP = xmlrpc_c::value_int(x - y);
    }
};

int main() {
    xmlrpc_c::registry myRegistry;
    xmlrpc_c::methodPtr const addMethodP(new addMethod);
    xmlrpc_c::methodPtr const subtractMethodP(new subtractMethod);

    myRegistry.addMethod("add", addMethodP);
    myRegistry.addMethod("subtract", subtractMethodP);

    xmlrpc_c::serverAbyss myAbyssServer(
        xmlrpc_c::serverAbyss::constrOpt()
        .registryP(&myRegistry)
        .portNumber(8000));

    myAbyssServer.run();
    return 0;
}