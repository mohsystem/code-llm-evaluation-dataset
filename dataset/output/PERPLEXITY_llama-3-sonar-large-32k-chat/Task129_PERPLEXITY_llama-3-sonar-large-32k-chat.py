import socket

def retrieve_file(file_name):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("localhost", 12345))
    client_socket.send(file_name.encode())
    response = client_socket.recv(1024)
    if response.decode() == "File not found":
        print("File not found on the server")
    else:
        with open(file_name, "wb") as f:
            while response:
                f.write(response)
                response = client_socket.recv(1024)
    client_socket.close()

file_name = input("Enter the file name: ")
retrieve_file(file_name)