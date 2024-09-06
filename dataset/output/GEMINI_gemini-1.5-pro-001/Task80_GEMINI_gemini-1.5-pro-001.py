import socket
import ssl

def create_ssl_client_socket_ipv6(hostname, port):
    """Creates an SSL client socket using IPv6 and TCP protocol.

    Args:
        hostname: The hostname of the server to connect to.
        port: The port number of the server to connect to.

    Returns:
        The established SSL socket.
    """

    # Create a TCP socket using IPv6
    sock = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)

    # Wrap the socket with SSL
    ssl_sock = ssl.wrap_socket(sock)

    # Connect to the server
    ssl_sock.connect((hostname, port))

    return ssl_sock