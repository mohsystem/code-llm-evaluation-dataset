
import socket
import ssl

def create_ssl_ipv6_socket(host, port):
    context = ssl.create_default_context()
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
    ssl_sock = context.wrap_socket(sock, server_hostname=host)
    ssl_sock.connect((host, port))
    return ssl_sock

# Usage example
# host = "example.com"
# port = 443
# ssl_socket = create_ssl_ipv6_socket(host, port)
