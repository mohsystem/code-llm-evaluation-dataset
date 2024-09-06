# Python code using RPyC
import rpyc

class MyService(rpyc.Service):
    def on_connect(self, conn):
        print("Client connected")

    def on_disconnect(self, conn):
        print("Client disconnected")

    def exposed_get_data(self):
        return "Hello from server!"

    def exposed_set_data(self, data):
        print("Received data from client:", data)

if __name__ == "__main__":
    from rpyc.utils.server import ThreadedServer
    t = ThreadedServer(MyService, port=18861)
    t.start()