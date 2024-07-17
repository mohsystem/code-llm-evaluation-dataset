import socket

def doSomething():
    print("Doing something on the server...")

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("localhost", 8080))
    server_socket.listen(1)

    connection, address = server_socket.accept()
    message = connection.recv(1024).decode()
    print(message)
    doSomething()
    connection.send("Hello from server".encode())
    print("Hello message sent")

if __name__ == "__main__":
    main()