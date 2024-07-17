import socket
import ssl

def main():
    if len(sys.argv) != 3:
        print("Usage: python secure_connection.py <hostname> <port>")
        sys.exit(1)

    hostname = sys.argv[1]
    port = int(sys.argv[2])

    context = ssl.create_default_context()

    with socket.create_connection((hostname, port)) as sock:
        with context.wrap_socket(sock, server_hostname=hostname) as ssock:
            print("Secure connection established:")
            print(f"Socket: {ssock}")

if __name__ == "__main__":
    main()