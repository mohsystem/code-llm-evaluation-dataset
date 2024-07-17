# Python
from xmlrpc.server import SimpleXMLRPCServer

def sample(param):
    return f"Received: {param}"

server = SimpleXMLRPCServer(("localhost", 8080))
server.register_function(sample, "sample")
server.serve_forever()