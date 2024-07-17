
import socket
import threading

HOST = \'127.0.0.1\'
PORT = 5000

clients = []
clients_lock = threading.Lock()

def broadcast(message, sender_conn):
    with clients_lock:
        for client in clients:
            if client != sender_conn:
                try:
                    client.send(message)
                except:
                    clients.remove(client)

def handle_client(conn, addr):
    print(f"New connection from {addr}")
    with clients_lock:
        clients.append(conn)
    
    try:
        while True:
            message = conn.recv(1024)
            if not message:
                break
            broadcast(message, conn)
    finally:
        with clients_lock:
            clients.remove(conn)
        conn.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"Server is listening on {HOST}:{PORT}")

    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()

if __name__ == "__main__":
    start_server()

# Chat Client
import socket
import threading

HOST = \'127.0.0.1\'
PORT = 5000

def receive_messages(sock):
    while True:
        try:
            message = sock.recv(1024).decode()
            if not message:
                break
            print(message)
        except:
            break

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))
    print(f"Connected to server at {HOST}:{PORT}")

    receive_thread = threading.Thread(target=receive_messages, args=(client,))
    receive_thread.start()

    try:
        while True:
            message = input()
            client.send(message.encode())
    except KeyboardInterrupt:
        print("Disconnecting from server...")
    finally:
        client.close()

if __name__ == "__main__":
    start_client()
