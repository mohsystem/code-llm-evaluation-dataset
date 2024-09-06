import socket
import ssl

hostname = 'www.google.com'
port = 443

# Create a context with default settings
context = ssl.create_default_context()

with socket.create_connection((hostname, port)) as sock:
    with context.wrap_socket(sock, server_hostname=hostname) as ssock:
        print(f"Connected to {hostname} on port {port}")
        print(f"SSL/TLS version: {ssock.version()}")
        print(f"Cipher suite: {ssock.cipher()}")