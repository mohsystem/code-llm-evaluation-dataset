import socket
import threading

HOST = '127.0.0.1'
PORT = 65432

clients = []
usernames = {}

def handle_client(client_socket):
    while True:
        try:
            message = client_socket.recv(1024).decode('ascii')
            if message:
                broadcast(message, client_socket)
            else:
                remove_client(client_socket)
                break
        except:
            remove_client(client_socket)
            break

def broadcast(message, client_socket):
    for client in clients:
        if client != client_socket:
            try:
                client.send(message.encode('ascii'))
            except:
                remove_client(client)

def remove_client(client_socket):
    if client_socket in clients:
        clients.remove(client_socket)
        client_socket.close()
        username = usernames[client_socket]
        del usernames[client_socket]
        broadcast(f'{username} has left the chat'.encode('ascii'), client_socket)

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f'Server started on {HOST}:{PORT}')

    while True:
        client_socket, client_address = server_socket.accept()
        clients.append(client_socket)
        client_socket.send('Enter your username: '.encode('ascii'))
        username = client_socket.recv(1024).decode('ascii')
        usernames[client_socket] = username
        print(f'{username} connected from {client_address}')
        broadcast(f'{username} joined the chat!'.encode('ascii'), client_socket)
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if __name__ == '__main__':
    start_server()