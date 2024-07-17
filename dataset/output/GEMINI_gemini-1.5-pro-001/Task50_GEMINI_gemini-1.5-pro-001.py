import socket
import os

HOST = '127.0.0.1'
PORT = 65432

def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")

    try:
        # Receive file name and size
        file_name = conn.recv(1024).decode()
        file_size = int(conn.recv(1024).decode())

        # Open file for writing
        with open(file_name, 'wb') as f:
            # Receive and write file data
            bytes_received = 0
            while bytes_received < file_size:
                data = conn.recv(1024)
                f.write(data)
                bytes_received += len(data)

        # Send confirmation message
        conn.send(f"File '{file_name}' uploaded successfully!".encode())

    except Exception as e:
        print(f"[ERROR] {e}")
        conn.send(f"Error uploading file: {e}".encode())

    finally:
        # Close connection
        conn.close()
        print(f"[DISCONNECTED] {addr} disconnected.")

# Create socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind socket to address
server_socket.bind((HOST, PORT))

# Listen for incoming connections
server_socket.listen()
print(f"[LISTENING] Server is listening on {HOST}:{PORT}")

while True:
    # Accept connection from client
    conn, addr = server_socket.accept()

    # Handle client connection in a separate thread
    client_thread = threading.Thread(target=handle_client, args=(conn, addr))
    client_thread.start()