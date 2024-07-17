
import socket
import os

def start_server():
    host = \'127.0.0.1\'
    port = 8080

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)

    print(f"Server started. Listening on port {port}...")

    while True:
        client_socket, address = server_socket.accept()
        print(f"Connection from {address}")

        filename = client_socket.recv(1024).decode()
        filesize = int(client_socket.recv(1024).decode())

        with open(os.path.join("uploads", filename), "wb") as f:
            bytes_received = 0
            while bytes_received < filesize:
                data = client_socket.recv(1024)
                f.write(data)
                bytes_received += len(data)

        client_socket.send("File uploaded successfully".encode())
        client_socket.close()

if __name__ == "__main__":
    start_server()
