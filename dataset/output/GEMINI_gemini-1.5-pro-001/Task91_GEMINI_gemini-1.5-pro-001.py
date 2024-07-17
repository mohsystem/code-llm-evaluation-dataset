import socket
import struct

# Define DNS port and maximum packet size
DNS_PORT = 53
MAX_PACKET_SIZE = 512

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the DNS port
server_address = ('localhost', DNS_PORT)
sock.bind(server_address)

print(f"DNS server listening on {server_address}")

# Define a dictionary to store DNS records
dns_records = {
    b'google.com': '172.217.160.142',
    b'facebook.com': '157.240.195.35'
}

def parse_dns_request(data):
    # Extract header fields
    header = struct.unpack('!HHHHHH', data[:12])
    transaction_id, flags, qdcount, ancount, nscount, arcount = header

    # Extract question section
    question = data[12:]
    qname = ''
    i = 0
    while True:
        length = question[i]
        if length == 0:
            break
        qname += question[i + 1:i + 1 + length].decode() + '.'
        i += length + 1
    qtype, qclass = struct.unpack('!HH', question[i + 1:i + 5])

    return transaction_id, qname[:-1], qtype, qclass

def create_dns_response(transaction_id, qname, qtype, qclass, ip_address):
    # Create header
    flags = 0x8180  # Response, recursion available
    header = struct.pack('!HHHHHH', transaction_id, flags, 1, 1, 0, 0)

    # Create question section
    question = b''.join(
        [len(part).to_bytes(1, 'big') + part.encode() for part in qname.split('.')]
    ) + b'\x00' + struct.pack('!HH', qtype, qclass)

    # Create answer section
    ttl = 3600
    answer = question + struct.pack(
        '!HHIH', qtype, qclass, ttl, 4
    ) + socket.inet_aton(ip_address)

    return header + question + answer

while True:
    # Receive DNS request
    data, address = sock.recvfrom(MAX_PACKET_SIZE)

    # Parse the DNS request
    transaction_id, qname, qtype, qclass = parse_dns_request(data)

    # Check if the requested domain is in the DNS records
    if qname in dns_records:
        # Resolve the IP address for the requested domain
        ip_address = dns_records[qname]

        # Create DNS response
        response = create_dns_response(transaction_id, qname, qtype, qclass, ip_address)

        # Send DNS response
        sock.sendto(response, address)