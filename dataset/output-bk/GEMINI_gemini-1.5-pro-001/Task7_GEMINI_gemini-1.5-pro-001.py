import socket
import threading

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

user_credentials = {
    "user1": "pass1",
    "user2": "pass2"
}

def handle_client(conn, addr):
    print(f"[CONNECTION] {addr} connected.")

    while True:
        data = conn.recv(1024).decode('utf-8')
        if not data:
            break
        
        command, username, password = data.split(" ", 2)

        if command == "LOGIN":
            if username in user_credentials and user_credentials[username] == password:
                response = "Welcome, " + username + "!"
            else:
                response = "Invalid username or password."
            conn.send(response.encode('utf-8'))
        else:
            conn.send("Invalid command.".encode('utf-8'))

    conn.close()
    print(f"[DISCONNECTION] {addr} disconnected.")

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen(5)
    print(f"[LISTENING] Server is listening on {HOST}:{PORT}")

    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1}")

if __name__ == "__main__":
    start_server()