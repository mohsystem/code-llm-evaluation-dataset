
import socket
import threading

class RemoteObject:
    def __init__(self):
        self.value = 0

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value

obj = RemoteObject()

def handle_client(client_socket):
    request = client_socket.recv(1024).decode(\'utf-8\')
    if request.startswith(\'GET\'):
        response = str(obj.get_value())
        client_socket.send(response.encode(\'utf-8\'))
    elif request.startswith(\'SET\'):
        new_value = int(request.split()[1])
        obj.set_value(new_value)
        client_socket.send(\'OK\'.encode(\'utf-8\'))
    client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((\'0.0.0.0\', 8080))
    server.listen(5)
    print("Server is running on port 8080...")

    while True:
        client, addr = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == "__main__":
    start_server()
