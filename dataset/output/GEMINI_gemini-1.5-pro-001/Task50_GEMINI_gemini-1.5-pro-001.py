import socket
import os

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

def handle_client(conn, addr):
    print(f"Connected by {addr}")
    with conn:
        while True:
            data = conn.recv(1024).decode('utf-8')
            if not data: break
            filename, filesize = data.split('<SEPARATOR>')
            filesize = int(filesize)

            conn.send(f"Receiving {filename}".encode('utf-8'))

            with open(filename, "wb") as f:
                bytes_read = conn.recv(filesize)
                f.write(bytes_read)

            conn.send(f"{filename} uploaded successfully!".encode('utf-8'))
    print(f"Disconnected from {addr}")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print(f"Server started on {HOST}:{PORT}")
    while True:
        conn, addr = s.accept()
        handle_client(conn, addr)