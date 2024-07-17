# Python code for the server
import socket
import threading

PORT = 1234
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "utf-8"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

clients = []
names = []

def broadcast(message):
    for client in clients:
        client.send(message)

def handle(client):
    while True:
        try:
            msg = message = client.recv(1024)
            if msg.decode(FORMAT).startswith("/quit"):
                index = clients.index(client)
                clients.remove(client)
                client.close()
                name = names[index]
                broadcast(f"{name} has left the chat!".encode(FORMAT))
                names.remove(name)
                break
            else:
                broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            name = names[index]
            broadcast(f"{name} has left the chat!".encode(FORMAT))
            names.remove(name)
            break

def start():
    server.listen()
    print(f"[LISTENING] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()
        conn.send("NAME".encode(FORMAT))
        name = conn.recv(1024).decode(FORMAT)
        names.append(name)
        clients.append(conn)
        broadcast(f"{name} has joined the chat!".encode(FORMAT))
        conn.send("Connected to the server!".encode(FORMAT))
        thread = threading.Thread(target=handle, args=(conn,))
        thread.start()

print("Chat Server is running...")
start()