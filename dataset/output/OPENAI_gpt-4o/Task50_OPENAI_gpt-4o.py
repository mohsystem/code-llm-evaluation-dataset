import os
import socket

PORT = 1234
UPLOAD_DIR = 'uploads/'

def handle_client(client_socket):
    file_name_len = int.from_bytes(client_socket.recv(1), byteorder='big')
    file_name = client_socket.recv(file_name_len).decode()
    
    file_size = int.from_bytes(client_socket.recv(8), byteorder='big')
    
    with open(os.path.join(UPLOAD_DIR, file_name), 'wb') as file:
        bytes_to_read = file_size
        while bytes_to_read > 0:
            chunk_size = 4096 if bytes_to_read > 4096 else bytes_to_read
            chunk = client_socket.recv(chunk_size)
            if not chunk:
                break
            file.write(chunk)
            bytes_to_read -= len(chunk)

    client_socket.sendall(b'File uploaded successfully')
    client_socket.close()

def main():
    if not os.path.exists(UPLOAD_DIR):
        os.makedirs(UPLOAD_DIR)

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('', PORT))
    server_socket.listen(5)
    print(f'Server listening on port {PORT}')

    while True:
        client_socket, _ = server_socket.accept()
        handle_client(client_socket)

if __name__ == '__main__':
    main()