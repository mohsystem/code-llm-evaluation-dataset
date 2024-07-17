from xmlrpc.server import SimpleXMLRPCServer

def add(x, y):
    return x + y

server = SimpleXMLRPCServer(("localhost", 8083))
server.register_function(add, "add")
print("Python XML-RPC server running on port 8083...")
server.serve_forever()