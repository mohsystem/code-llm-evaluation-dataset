import socket
import ssl

def ssl_connect(hostname, port):
    context = ssl.create_default_context()
    with socket.create_connection((hostname, port)) as sock:
        with context.wrap_socket(sock, server_hostname=hostname) as ssock:
            print(ssock.version())
            ssock.send(b"Hello, world!")
            response = ssock.recv(1024)
            print(response)

ssl_connect("www.example.com", 443)