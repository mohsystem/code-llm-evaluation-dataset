import socket
import os

def retrieve_file(filename):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 8080)
    sock.connect(server_address)
    sock.sendall(filename.encode())
    data = sock.recv(1024)
    if data:
        f = open(filename, 'wb')
        f.write(data)
        f.close()
        print("File retrieved successfully")
    else:
        print("File not found on the server")
    sock.close()

filename = input("Enter the filename: ")
retrieve_file(filename)