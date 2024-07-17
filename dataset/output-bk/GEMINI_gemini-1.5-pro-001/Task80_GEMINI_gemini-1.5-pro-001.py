import socket
import ssl

HOST = "localhost"
PORT = 8443

def create_ssl_socket(host, port):
    # Create a TCP socket
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)

    # Wrap the socket with SSL
    ssl_sock = ssl.wrap_socket(sock)

    # Connect to the server
    ssl_sock.connect((host, port))

    return ssl_sock

if __name__ == "__main__":
    try:
        sock = create_ssl_socket(HOST, PORT)
        print(f"Connected to: {HOST}:{PORT}")
        sock.close()
    except Exception as e:
        print(f"Error: {e}")