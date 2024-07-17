#include <iostream>
#include <xmlrpc/XmlRpc.h>

using namespace std;

class MyXmlRpcServer : public XmlRpcServer {
public:
    MyXmlRpcServer() {
        // Bind "add" procedure to the server
        this->bindAndExecuteMethod(XmlRpcServer::XmlRpcMethodPtr(
                new XmlRpcServerMethod("add", this)));
    }

    // Method to be exposed to XML-RPC clients
    void add(XmlRpcServerMethodCaller& caller,
              const XmlRpcValue& params, XmlRpcValue& result) {
        if (params.getType() != XmlRpcValue::TypeArray || params.arraySize() != 2) {
            throw XmlRpcException("Invalid parameters. Expecting an array of two numbers.");
        }

        double a = params[0];
        double b = params[1];
        result = a + b;
    }
};

int main() {
    try {
        MyXmlRpcServer server;
        cout << "Starting XML-RPC server on port 8080..." << endl;
        server.acceptConnectionsOnPort(8080);
        server.run();
    } catch (XmlRpcException& e) {
        cerr << "XML-RPC Exception: " << e.getMessage() << endl;
        return 1;
    }

    return 0;
}
