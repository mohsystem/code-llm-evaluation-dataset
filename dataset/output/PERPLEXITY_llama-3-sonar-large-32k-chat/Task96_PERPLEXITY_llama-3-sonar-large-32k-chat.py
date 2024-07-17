import socket

def echo_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("localhost", 8000))
    server_socket.listen(1)
    print("Server is running...")
    connection, address = server_socket.accept()
    print("Client connected...")

    while True:
        data = connection.recv(1024)
        if not data:
            break
        print("Server:", data.decode())
        connection.sendall(data)

if __name__ == "__main__":
    echo_server()