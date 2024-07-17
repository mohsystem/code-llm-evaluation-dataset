
import socket
import ssl

def create_ssl_socket(host, port):
    # Create a TCP/IPv6 socket
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
    
    # Wrap the socket with SSL
    context = ssl.create_default_context()
    ssl_sock = context.wrap_socket(sock, server_hostname=host)
    
    try:
        # Connect to the server
        ssl_sock.connect((host, port))
        print(f"Connected to {host}:{port}")
        return ssl_sock
    except Exception as e:
        print(f"Connection failed: {e}")
        ssl_sock.close()
        return None

def main():
    host = "2001:db8::1"
    port = 443
    
    ssl_socket = create_ssl_socket(host, port)
    if ssl_socket:
        # Do something with the socket
        print("SSL Handshake completed")
        
        # Close the socket when done
        ssl_socket.close()

if __name__ == "__main__":
    main()
