import socket
import threading

HOST = '127.0.0.1'
PORT = 65432

client_list = []

def handle_client(client_socket):
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if message:
                broadcast(message, client_socket)
            else:
                client_list.remove(client_socket)
                client_socket.close()
                break
        except:
            client_list.remove(client_socket)
            client_socket.close()
            break

def broadcast(message, client_socket):
    for client in client_list:
        if client != client_socket:
            try:
                client.send(message.encode('utf-8'))
            except:
                client.close()
                client_list.remove(client)

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen(5)

print(f"Server started on {HOST}:{PORT}")

while True:
    client_socket, address = server_socket.accept()
    client_list.append(client_socket)
    print(f"Client connected from {address}")

    client_thread = threading.Thread(target=handle_client, args=(client_socket,))
    client_thread.start()