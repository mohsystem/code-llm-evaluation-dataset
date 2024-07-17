from SimpleXMLRPCServer import SimpleXMLRPCServer

class MyHandler:
    def add(self, a, b):
        return a + b

    def echo(self, message):
        return message

server = SimpleXMLRPCServer(("localhost", 8080))
server.register_instance(MyHandler())
server.serve_forever()