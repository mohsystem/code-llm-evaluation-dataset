
import ssl
import socket

def create_ssl_connection(host, port):
    context = ssl.create_default_context()
    with socket.create_connection((host, port)) as sock:
        with context.wrap_socket(sock, server_hostname=host) as secure_sock:
            print(f"Connected to {host}:{port}")
            print(f"SSL version: {secure_sock.version()}")
            print(f"Cipher: {secure_sock.cipher()}")
            cert = secure_sock.getpeercert()
            print(f"Certificate: {cert}")

if __name__ == "__main__":
    create_ssl_connection("www.example.com", 443)
