import socket
import ssl

def create_ssl_socket(host, port):
    context = ssl.create_default_context()
    with socket.create_connection((host, port)) as sock:
        with context.wrap_socket(sock, server_hostname=host) as ssock:
            return ssock

if __name__ == "__main__":
    ssl_socket = create_ssl_socket("::1", 443)
    print("Connected to ::1:443")