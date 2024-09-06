# Python - Server
import socket
import threading

def handle_client(client_socket):
    while True:
        try:
            data = client_socket.recv(1024).decode("utf-8")
            if not data:
                break

            credentials = data.split(':')
            if len(credentials) != 2:
                client_socket.send("Invalid format. Use username:password\n".encode("utf-8"))
                continue

            username, password = credentials[0], credentials[1]
            
            with open("users.txt", "r") as f:
                users = f.read().splitlines()
                auth = f"{username}:{password}" in users
                
            if auth:
                client_socket.send("Login successful\n".encode("utf-8"))
            else:
                client_socket.send("Login failed\n".encode("utf-8"))
        except:
            client_socket.close()
            break

def server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", 12345))
    server_socket.listen(5)
    print("Server listening on port 12345")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()
        
if __name__ == "__main__":
    server()