
import socket
import threading

PORT = 5000
SERVER = "localhost"

def load_users():
    users = {}
    with open("users.txt", "r") as file:
        for line in file:
            username, password = line.strip().split(":")
            users[username] = password
    return users

class ChatServer:
    def __init__(self):
        self.users = load_users()
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((SERVER, PORT))

    def start(self):
        self.server.listen()
        print(f"Server is listening on {SERVER}:{PORT}")
        while True:
            conn, addr = self.server.accept()
            thread = threading.Thread(target=self.handle_client, args=(conn, addr))
            thread.start()

    def handle_client(self, conn, addr):
        print(f"New connection from {addr}")
        try:
            data = conn.recv(1024).decode()
            command, username, password = data.split("|")
            if command == "LOGIN":
                if username in self.users and self.users[username] == password:
                    conn.send("LOGIN_SUCCESS".encode())
                else:
                    conn.send("LOGIN_FAILED".encode())
        finally:
            conn.close()

class ChatClient:
    def __init__(self):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        self.client.connect((SERVER, PORT))

    def login(self, username, password):
        request = f"LOGIN|{username}|{password}"
        self.client.send(request.encode())
        response = self.client.recv(1024).decode()
        return response

if __name__ == "__main__":
    import sys

    if len(sys.argv) < 2:
        print("Usage: python script.py [server|client]")
        sys.exit(1)

    if sys.argv[1] == "server":
        server = ChatServer()
        server.start()
    elif sys.argv[1] == "client":
        client = ChatClient()
        client.connect()
        username = input("Enter username: ")
        password = input("Enter password: ")
        response = client.login(username, password)
        print(f"Server response: {response}")
    else:
        print("Invalid argument. Use \'server\' or \'client\'.")
