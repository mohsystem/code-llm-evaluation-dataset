import socket
import threading
import pickle

objects = {}

def handle_client(client_socket):
    action = pickle.loads(client_socket.recv(4096))
    key = pickle.loads(client_socket.recv(4096))
    if action == "put":
        value = pickle.loads(client_socket.recv(4096))
        objects[key] = value
        client_socket.send(pickle.dumps("Success"))
    elif action == "get":
        value = objects.get(key, None)
        client_socket.send(pickle.dumps(value))
    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 7896))
    server.listen(5)
    while True:
        client_socket, addr = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()

if __name__ == "__main__":
    main()