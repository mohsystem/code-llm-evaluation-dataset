import ssl
import socket

# Define the remote server and port
server = 'www.example.com'
port = 443

# Create a socket object
sock = socket.create_connection((server, port))

# Wrap the socket with SSL/TLS
context = ssl.create_default_context()
ssl_sock = context.wrap_socket(sock, server_hostname=server)

# Now you can use ssl_sock to communicate with the server securely