import socket
import ssl

def create_ssl_client_socket(host, port):
    context = ssl.create_default_context()
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
    conn = context.wrap_socket(sock, server_hostname=host)
    conn.connect((host, port))
    return conn