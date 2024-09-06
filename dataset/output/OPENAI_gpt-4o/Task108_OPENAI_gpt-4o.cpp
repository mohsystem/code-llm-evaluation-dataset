// C++ Remote Object Manipulation Server (example)
#include <iostream>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class RemoteObject {
public:
    RemoteObject() : value(0) {}
    
    void setValue(int v) {
        value = v;
    }
    
    int getValue() const {
        return value;
    }

private:
    int value;
};

class setValueMethod : public xmlrpc_c::method {
public:
    setValueMethod(RemoteObject* obj) : remoteObject(obj) {}

    void execute(const xmlrpc_c::paramList& paramList, xmlrpc_c::value* retval) {
        int value = paramList.getInt(0);
        remoteObject->setValue(value);
        *retval = xmlrpc_c::value_string("Value set to " + std::to_string(value));
    }

private:
    RemoteObject* remoteObject;
};

class getValueMethod : public xmlrpc_c::method {
public:
    getValueMethod(RemoteObject* obj) : remoteObject(obj) {}

    void execute(const xmlrpc_c::paramList& paramList, xmlrpc_c::value* retval) {
        int value = remoteObject->getValue();
        *retval = xmlrpc_c::value_int(value);
    }

private:
    RemoteObject* remoteObject;
};

int main() {
    RemoteObject obj;
    xmlrpc_c::registry myRegistry;

    xmlrpc_c::methodPtr const setValueP(new setValueMethod(&obj));
    xmlrpc_c::methodPtr const getValueP(new getValueMethod(&obj));
    
    myRegistry.addMethod("set_value", setValueP);
    myRegistry.addMethod("get_value", getValueP);

    xmlrpc_c::serverAbyss myServer(xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(8000));
    std::cout << "Server is running..." << std::endl;
    myServer.run();
    
    return 0;
}