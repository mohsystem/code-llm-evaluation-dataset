# Python
import socket
import pickle

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 8080))
server_socket.listen(5)
client_socket, addr = server_socket.accept()

# Add your object manipulation logic here