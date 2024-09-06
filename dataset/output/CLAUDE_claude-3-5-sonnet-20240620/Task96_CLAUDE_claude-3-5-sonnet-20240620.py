
import socket

def start_server(port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', port))
    server_socket.listen(1)
    print(f"Server listening on port {port}")

    while True:
        client_socket, address = server_socket.accept()
        print(f"Connection from {address}")
        
        while True:
            data = client_socket.recv(1024).decode('utf-8')
            if not data:
                break
            print(f"Received: {data}")
            client_socket.send(data.encode('utf-8'))
        
        client_socket.close()

if __name__ == "__main__":
    start_server(12345)
