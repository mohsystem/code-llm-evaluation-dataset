import socket
import threading

def handle_client(client_socket):
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if message:
                broadcast(message, client_socket)
            else:
                remove(client_socket)
        except:
            continue

def broadcast(message, connection):
    for client in clients:
        if client != connection:
            try:
                client.send(message.encode('utf-8'))
            except:
                remove(client)

def remove(connection):
    if connection in clients:
        clients.remove(connection)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('0.0.0.0', 5555))
server.listen(100)

clients = []

print("Server started...")

while True:
    client_socket, addr = server.accept()
    clients.append(client_socket)
    print(f"Connection established with {addr}")
    client_handler = threading.Thread(target=handle_client, args=(client_socket,))
    client_handler.start()