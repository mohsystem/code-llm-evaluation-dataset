
import xmlrpc.server

class MyFunctions:
    def add(self, x, y):
        return x + y

    def subtract(self, x, y):
        return x - y

server = xmlrpc.server.SimpleXMLRPCServer(("localhost", 8000))
server.register_instance(MyFunctions())
print("XML-RPC server is running on port 8000...")
server.serve_forever()
