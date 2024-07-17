
import socket
import threading

PORT = 12345
HOST = \'\'
BUFFER_SIZE = 1024

clients = []
clients_lock = threading.Lock()

def handle_client(client_socket, client_address):
    while True:
        try:
            message = client_socket.recv(BUFFER_SIZE).decode(\'utf-8\')
            if not message:
                break
            print(f"Received from {client_address}: {message}")
            broadcast(message, client_socket)
        except:
            break

    with clients_lock:
        clients.remove(client_socket)
    client_socket.close()

def broadcast(message, sender_socket):
    with clients_lock:
        for client in clients:
            if client != sender_socket:
                try:
                    client.send(message.encode(\'utf-8\'))
                except:
                    clients.remove(client)

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen(5)

    print(f"Chat Server is running on port {PORT}...")

    while True:
        client_socket, client_address = server.accept()
        print(f"New connection from {client_address}")

        with clients_lock:
            clients.append(client_socket)

        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()

if __name__ == "__main__":
    main()
