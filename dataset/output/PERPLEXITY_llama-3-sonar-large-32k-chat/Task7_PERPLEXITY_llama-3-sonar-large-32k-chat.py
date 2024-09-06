# Python Code (Server)
import socket
import os

def authenticate(username, password):
    with open("users.txt", "r") as file:
        for line in file:
            user, pwd = line.strip().split(":")
            if user == username and pwd == password:
                return True
    return False

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 10000)
    sock.bind(server_address)
    sock.listen(1)

    print("Server started. Waiting for connections...")
    connection, address = sock.accept()
    print(f"Connected to {address}")

    while True:
        data = connection.recv(1024).decode()
        if data.startswith("LOGIN"):
            username, password = data.split()[1], data.split()[2]
            if authenticate(username, password):
                connection.sendall("LOGIN_SUCCESS".encode())
            else:
                connection.sendall("LOGIN_FAILED".encode())
        else:
            print(f"Received message: {data}")
            connection.sendall(f"Server received your message: {data}".encode())

if __name__ == "__main__":
    main()