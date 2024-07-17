# Python
import socket
import threading

clients = []
lock = threading.Lock()

def handle_client(client_socket):
    try:
        while True:
            message = client_socket.recv(1024).decode("utf-8")
            if not message:
                break
            
            with lock:
                for client in clients:
                    if client != client_socket:
                        client.sendall(message.encode("utf-8"))
    finally:
        with lock:
            clients.remove(client_socket)
        client_socket.close()

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", 12345))
    server_socket.listen(5)
    print("Chat server started...")

    try:
        while True:
            client_socket, addr = server_socket.accept()
            
            with lock:
                clients.append(client_socket)
            
            threading.Thread(target=handle_client, args=(client_socket,)).start()
    finally:
        server_socket.close()

if __name__ == "__main__":
    main()