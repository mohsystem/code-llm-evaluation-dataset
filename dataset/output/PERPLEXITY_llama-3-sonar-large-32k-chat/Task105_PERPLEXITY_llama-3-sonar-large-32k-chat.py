import socket
import ssl

HOST = "www.example.com"
PORT = 443

context = ssl.create_default_context()
with socket.create_connection((HOST, PORT)) as sock:
    with context.wrap_socket(sock, server_hostname=HOST) as ssock:
        request = b"GET / HTTP/1.1\r
"
        request += b"Host: " + HOST.encode() + b"\r
"
        request += b"Accept: */*\r
"
        request += b"\r
"
        ssock.sendall(request)

        while True:
            data = ssock.recv(1024)
            if not data:
                break
            print(data.decode())