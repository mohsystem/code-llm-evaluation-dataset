# Server side
import socket

def authenticate(username, password):
    # Implement authentication logic here
    # For demonstration purposes, assume authentication is successful
    return True

def server_program():
    host = '127.0.0.1'
    port = 8000

    server_socket = socket.socket()
    server_socket.bind((host, port))

    server_socket.listen(2)
    conn, address = server_socket.accept()
    print("Connection from: " + str(address))

    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        username, password = data.split(",")
        if authenticate(username, password):
            conn.send("Login successful!".encode())
        else:
            conn.send("Invalid credentials".encode())

    conn.close()

if __name__ == '__main__':
    server_program()

# Client side
import socket

def client_program():
    host = '127.0.0.1'
    port = 8000

    client_socket = socket.socket()
    client_socket.connect((host, port))

    message = input("Enter username: ") + "," + input("Enter password: ")
    client_socket.send(message.encode())

    data = client_socket.recv(1024).decode()
    print("Received from server: " + data)

    client_socket.close()

if __name__ == '__main__':
    client_program()