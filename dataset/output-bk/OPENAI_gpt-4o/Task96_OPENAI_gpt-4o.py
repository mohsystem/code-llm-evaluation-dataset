import socket

def start_server():
    # Python Code Block
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', 8083))
    server_socket.listen(5)
    print('Python Server listening on port 8083...')
    
    while True:
        client_socket, addr = server_socket.accept()
        with client_socket:
            print('Connected by', addr)
            while True:
                data = client_socket.recv(1024)
                if not data:
                    break
                client_socket.sendall(b'Echo: ' + data)

if __name__ == '__main__':
    start_server()