
import ssl
import socket

def ssl_connection():
    hostname = \'example.com\'
    context = ssl.create_default_context()

    with socket.create_connection((hostname, 443)) as sock:
        with context.wrap_socket(sock, server_hostname=hostname) as secure_sock:
            print(f"Connected to {hostname}")
            
            # Send HTTP GET request
            request = f"GET / HTTP/1.1\\r\
Host: {hostname}\\r\
\\r\
"
            secure_sock.send(request.encode())
            
            # Receive and print response
            response = secure_sock.recv(4096)
            print(response.decode())

if __name__ == "__main__":
    ssl_connection()
