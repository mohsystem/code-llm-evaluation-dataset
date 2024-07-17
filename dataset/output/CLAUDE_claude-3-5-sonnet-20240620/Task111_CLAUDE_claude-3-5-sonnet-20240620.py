
from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = (\'/RPC2\',)

def add(x, y):
    return x + y

server = SimpleXMLRPCServer(("localhost", 8080),
                            requestHandler=RequestHandler)
server.register_function(add, \'add\')

print("XML-RPC server running on port 8080...")
server.serve_forever()
