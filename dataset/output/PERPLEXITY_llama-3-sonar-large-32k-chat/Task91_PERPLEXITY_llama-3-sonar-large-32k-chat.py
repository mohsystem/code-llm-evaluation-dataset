import socket

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific IP address and port
server_address = ('localhost', 53)
sock.bind(server_address)

print('Starting UDP server on {} port {}'.format(*server_address))

while True:
    # Receive data from client
    data, address = sock.recvfrom(4096)

    # Parse the received data (DNS request)
    # This is a simplified example, in real-world scenarios you would need to parse the DNS request using a library like dnspython
    print('Received {} bytes from {}'.format(len(data), address))
    print(data.decode())

    # Resolve DNS records (this is a simplified example, in real-world scenarios you would need to use a DNS resolver library)
    dns_response = 'DNS response'

    # Send the response back to the client
    sent = sock.sendto(dns_response.encode(), address)
    print('Sent {} bytes back to {}'.format(sent, address))