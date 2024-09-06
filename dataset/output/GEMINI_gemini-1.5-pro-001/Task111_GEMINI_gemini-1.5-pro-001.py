from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

# Create server
with SimpleXMLRPCServer(('localhost', 8000),
                       requestHandler=RequestHandler) as server:
    server.register_introspection_functions()

    # Register pow() function; this will use the Python/C math library
    def pow(x, y):
        return x**y
    server.register_function(pow)

    # Register an add function
    def add(x, y):
        return x + y
    server.register_function(add)

    # Register a function under function ID 'sum'
    server.register_function(sum, 'sum')

    # Run the server forever
    print("Serving XML-RPC on localhost port 8000...")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nKeyboard interrupt received, exiting.")