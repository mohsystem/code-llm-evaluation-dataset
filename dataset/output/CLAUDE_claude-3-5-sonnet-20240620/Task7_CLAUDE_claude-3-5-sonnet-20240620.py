
import socket
import threading
import json
import os

# Server
class Server:
    def __init__(self, host='localhost', port=5000):
        self.host = host
        self.port = port
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((self.host, self.port))
        self.clients = []

    def start(self):
        self.server_socket.listen()
        print(f"Server listening on {self.host}:{self.port}")
        while True:
            client_socket, address = self.server_socket.accept()
            client_thread = threading.Thread(target=self.handle_client, args=(client_socket,))
            client_thread.start()

    def handle_client(self, client_socket):
        while True:
            try:
                data = client_socket.recv(1024).decode('utf-8')
                if not data:
                    break
                request = json.loads(data)
                if request['action'] == 'login':
                    response = self.authenticate(request['username'], request['password'])
                    client_socket.send(json.dumps(response).encode('utf-8'))
            except:
                break
        client_socket.close()

    def authenticate(self, username, password):
        # Simple file-based authentication
        if os.path.exists('users.txt'):
            with open('users.txt', 'r') as file:
                for line in file:
                    stored_username, stored_password = line.strip().split(':')
                    if username == stored_username and password == stored_password:
                        return {'status': 'success', 'message': 'Login successful'}
        return {'status': 'failure', 'message': 'Invalid credentials'}

# Client
class Client:
    def __init__(self, host='localhost', port=5000):
        self.host = host
        self.port = port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        self.client_socket.connect((self.host, self.port))

    def login(self):
        username = input("Enter username: ")
        password = input("Enter password: ")
        request = {
            'action': 'login',
            'username': username,
            'password': password
        }
        self.client_socket.send(json.dumps(request).encode('utf-8'))
        response = json.loads(self.client_socket.recv(1024).decode('utf-8'))
        print(response['message'])

    def start(self):
        self.connect()
        self.login()

if __name__ == "__main__":
    choice = input("Enter 's' for server, 'c' for client: ")
    if choice.lower() == 's':
        server = Server()
        server.start()
    elif choice.lower() == 'c':
        client = Client()
        client.start()
    else:
        print("Invalid choice")
