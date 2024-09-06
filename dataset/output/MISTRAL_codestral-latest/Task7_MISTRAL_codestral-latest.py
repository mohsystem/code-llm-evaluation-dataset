# Python client
import socket

def login():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    return f"LOGIN|{username}|{password}"

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))
    message = login()
    client_socket.send(message.encode())
    response = client_socket.recv(1024).decode()
    print(response)
    client_socket.close()

if __name__ == "__main__":
    main()