# Python does not have built-in support for IPv6-only sockets, so we'll use the socket library with AF_INET6
import socket
import ssl

def create_ssl_client_socket(host, port):
    context = ssl.create_default_context()
    sock = socket.create_connection((host, port), family=socket.AF_INET6)
    ssl_sock = context.wrap_socket(sock, server_hostname=host)
    return ssl_sock