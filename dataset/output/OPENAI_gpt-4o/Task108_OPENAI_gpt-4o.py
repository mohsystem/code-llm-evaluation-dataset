# Python Remote Object Manipulation Server (example)
from xmlrpc.server import SimpleXMLRPCServer

class RemoteObject:
    def __init__(self):
        self.value = 0

    def set_value(self, value):
        self.value = value
        return f"Value set to {self.value}"

    def get_value(self):
        return self.value

server = SimpleXMLRPCServer(("localhost", 8000))
obj = RemoteObject()

server.register_function(obj.set_value, "set_value")
server.register_function(obj.get_value, "get_value")

print("Server is running...")
server.serve_forever()