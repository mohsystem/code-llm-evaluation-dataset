// C++
// This is a simplified example using xmlrpc-c++.
// A real-world application would require more complex error handling and memory management.
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>

class XmlRpcServer {
public:
    XmlRpcServer() : server(8080, nullptr, nullptr) {
        registry.addMethod("sample", &XmlRpcServer::method_sample, this);
        server.setRegistry(registry);
    }

    void run() {
        server.run();
    }

private:
    xmlrpc_c::serverAbyss server;
    xmlrpc_c::registry registry;

    xmlrpc_c::value method_sample(xmlrpc_c::paramList const& paramList) {
        std::string param = xmlrpc_c::value_string(paramList.getString(0));
        return xmlrpc_c::value_struct("result", param);
    }
};

int main() {
    XmlRpcServer server;
    server.run();
    return 0;
}