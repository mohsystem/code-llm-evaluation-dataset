import socket
import ssl

def create_ssl_client_socket(hostname, port):
    context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
    ssl_sock = context.wrap_socket(sock, server_hostname=hostname)
    ssl_sock.connect((hostname, port))
    print(f"Connected to {ssl_sock.getpeername()}")
    return ssl_sock

if __name__ == "__main__":
    create_ssl_client_socket("hostname", 443)