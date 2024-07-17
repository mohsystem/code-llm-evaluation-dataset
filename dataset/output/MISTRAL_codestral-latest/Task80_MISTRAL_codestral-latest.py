import socket
import ssl

def create_ssl_client_socket(host, port):
    context = ssl.create_default_context()
    ssl_socket = context.wrap_socket(socket.socket(socket.AF_INET6, socket.SOCK_STREAM), server_hostname=host)
    ssl_socket.connect((host, port))
    return ssl_socket