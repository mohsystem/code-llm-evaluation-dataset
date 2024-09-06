# Python
import socket
import pickle

class Server:
    def __init__(self, host='127.0.0.1', port=55555):
        self.host = host
        self.port = port
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((self.host, self.port))
        self.server.listen()
        self.objects = {}

    def run(self):
        while True:
            conn, addr = self.server.accept()
            data = conn.recv(4096)
            request = pickle.loads(data)
            self.handle_request(request, conn)

    def handle_request(self, request, conn):
        # Handle the request here. This could involve creating,
        # retrieving, updating, or deleting objects.
        pass

class Client:
    def __init__(self, host='127.0.0.1', port=55555):
        self.host = host
        self.port = port
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((self.host, self.port))

    def send_request(self, request):
        data = pickle.dumps(request)
        self.client.send(data)