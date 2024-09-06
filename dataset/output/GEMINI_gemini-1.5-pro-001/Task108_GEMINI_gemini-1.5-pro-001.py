import socket
import pickle

class RemoteObjectServer:
    def __init__(self, host='localhost', port=5000):
        self.host = host
        self.port = port
        self.objects = {}

    def start(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
            server_socket.bind((self.host, self.port))
            server_socket.listen(1)
            print(f"Server started on {self.host}:{self.port}")

            while True:
                client_socket, client_address = server_socket.accept()
                print(f"Client connected from {client_address}")
                self.handle_client(client_socket)

    def handle_client(self, client_socket):
        while True:
            try:
                data = client_socket.recv(1024)
                if not data:
                    break
                command, *args = pickle.loads(data)
                if command == 'CREATE':
                    object_id, object_data = args
                    self.objects[object_id] = object_data
                elif command == 'GET':
                    object_id = args[0]
                    data = pickle.dumps(self.objects.get(object_id))
                    client_socket.sendall(data)
                elif command == 'SET':
                    object_id, attribute, value = args
                    setattr(self.objects[object_id], attribute, value)
                elif command == 'CALL':
                    object_id, method, *method_args = args
                    method_result = getattr(self.objects[object_id], method)(*method_args)
                    data = pickle.dumps(method_result)
                    client_socket.sendall(data)
            except Exception as e:
                print(f"Error handling client request: {e}")
                break
        client_socket.close()

if __name__ == '__main__':
    server = RemoteObjectServer()
    server.start()