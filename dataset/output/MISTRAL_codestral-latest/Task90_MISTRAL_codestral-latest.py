# Python
import socket
import threading

clients = []

def handle_client(client):
    while True:
        try:
            message = client.recv(1024).decode('ascii')
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            break

def broadcast(message):
    for client in clients:
        client.send(message.encode('ascii'))

def start():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', 12345))
    server.listen()

    while True:
        client, addr = server.accept()
        clients.append(client)
        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()

start()