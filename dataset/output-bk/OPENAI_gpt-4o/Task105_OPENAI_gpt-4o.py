import ssl
import socket

hostname = 'google.com'
context = ssl.create_default_context()
with socket.create_connection((hostname, 443)) as sock:
    with context.wrap_socket(sock, server_hostname=hostname) as ssock:
        ssock.sendall(b"GET / HTTP/1.0\r
Host: google.com\r
\r
")
        while True:
            data = ssock.recv(1024)
            if not data:
                break
            print(data.decode('utf-8'), end='')