import ssl
import socket

context = ssl.create_default_context()

with socket.create_connection(("www.example.com", 443)) as sock:
    with context.wrap_socket(sock, server_hostname="www.example.com") as ssock:
        # Use ssock to communicate with the server
        pass