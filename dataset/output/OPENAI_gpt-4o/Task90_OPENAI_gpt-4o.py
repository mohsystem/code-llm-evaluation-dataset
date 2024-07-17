# Python code
import socket
import threading

clients = []
clients_lock = threading.Lock()

def handle_client(client_socket):
    while True:
        try:
            message = client_socket.recv(1024).decode()
            if not message:
                break
            with clients_lock:
                for client in clients:
                    if client != client_socket:
                        client.sendall(message.encode())
        except:
            break
    with clients_lock:
        clients.remove(client_socket)
    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', 12345))
    server.listen(5)
    print('Server started on port 12345')

    while True:
        client_socket, _ = server.accept()
        with clients_lock:
            clients.append(client_socket)
        threading.Thread(target=handle_client, args=(client_socket,)).start()

if __name__ == "__main__":
    main()