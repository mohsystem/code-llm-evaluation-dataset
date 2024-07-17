import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("localhost", 8000))
    server_socket.listen(5)
    print("Server started. Listening for incoming connections...")

    client_socket, address = server_socket.accept()
    print("Incoming connection from", address)

    with open("uploaded_file", "wb") as fp:
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            fp.write(data)

    print("File uploaded successfully!")

if __name__ == "__main__":
    start_server()