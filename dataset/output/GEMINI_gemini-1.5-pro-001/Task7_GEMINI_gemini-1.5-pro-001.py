import socket
import threading

HOST = '127.0.0.1'
PORT = 65432

client_list = []
usernames = {}

def handle_client(client_socket):
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if message:
                print(f"Received message: {message}")
                broadcast(message, client_socket)
            else:
                remove_client(client_socket)
                break
        except:
            remove_client(client_socket)
            break

def broadcast(message, client_socket):
    for client in client_list:
        if client != client_socket:
            try:
                client.send(message.encode('utf-8'))
            except:
                remove_client(client)

def remove_client(client_socket):
    client_list.remove(client_socket)
    client_socket.close()
    username = usernames[client_socket]
    del usernames[client_socket]
    broadcast(f"{username} has left the chat!".encode('utf-8'), client_socket)

def authenticate_user(username, password):
    with open('users.txt', 'r') as f:
        for line in f:
            u, p = line.strip().split(':')
            if u == username and p == password:
                return True
    return False

def handle_login(client_socket):
    client_socket.send("Enter username: ".encode('utf-8'))
    username = client_socket.recv(1024).decode('utf-8')
    client_socket.send("Enter password: ".encode('utf-8'))
    password = client_socket.recv(1024).decode('utf-8')
    if authenticate_user(username, password):
        client_socket.send("Login successful!".encode('utf-8'))
        usernames[client_socket] = username
        client_list.append(client_socket)
        broadcast(f"{username} has joined the chat!".encode('utf-8'), client_socket)
        threading.Thread(target=handle_client, args=(client_socket,)).start()
    else:
        client_socket.send("Invalid credentials!".encode('utf-8'))
        client_socket.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"Server listening on {HOST}:{PORT}")

    while True:
        client_socket, address = server_socket.accept()
        print(f"Connection from {address} established!")
        threading.Thread(target=handle_login, args=(client_socket,)).start()

if __name__ == '__main__':
    start_server()