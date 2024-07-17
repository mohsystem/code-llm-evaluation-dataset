import socket
import threading

users = {'user1': 'pass1', 'user2': 'pass2'}

def handle_client(client_socket):
    request = client_socket.recv(1024).decode('utf-8')
    username, password = request.split(',')
    response = "Login failed"
    if users.get(username) == password:
        response = "Login success"
    client_socket.send(response.encode('utf-8'))
    client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('0.0.0.0', 12345))
    server.listen(5)
    print("Server started on port 12345.")
    while True:
        client_socket, addr = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client_socket,))
        client_handler.start()
    
def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('127.0.0.1', 12345))
    username = input("Enter username: ")
    password = input("Enter password: ")
    request = f"{username},{password}"
    client.send(request.encode('utf-8'))
    response = client.recv(4096).decode('utf-8')
    print("Server response:", response)
    client.close()

if __name__ == "__main__":
    threading.Thread(target=start_server).start()
    threading.Thread(target=start_client).start()