import socket
import threading

class Server:
    def __init__(self):
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind(("localhost", 8000))
        self.server_socket.listen(5)
        self.clients = []

    def broadcast(self, message):
        for client in self.clients:
            client.send(message.encode())

    def handle_client(self, client_socket):
        while True:
            message = client_socket.recv(1024).decode()
            print("Received from client:", message)
            self.broadcast(message)

    def run(self):
        print("Server started. Waiting for clients...")
        while True:
            client_socket, address = self.server_socket.accept()
            print("Client connected")
            self.clients.append(client_socket)
            threading.Thread(target=self.handle_client, args=(client_socket,)).start()

class Client:
    def __init__(self):
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect(("localhost", 8000))

    def receive(self):
        while True:
            message = self.client_socket.recv(1024).decode()
            print("Received from server:", message)

    def send(self):
        while True:
            message = input()
            self.client_socket.send(message.encode())

    def run(self):
        threading.Thread(target=self.receive).start()
        self.send()

if __name__ == "__main__":
    server = Server()
    server.run()
    # client = Client()
    # client.run()