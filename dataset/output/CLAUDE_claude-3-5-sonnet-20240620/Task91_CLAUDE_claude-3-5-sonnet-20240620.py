
import socket
import struct

PORT = 53
BUFFER_SIZE = 512

def parse_dns_query(query):
    domain_name = ""
    pos = 12  # Skip header
    while pos < len(query) and query[pos] != 0:
        label_length = query[pos]
        pos += 1
        domain_name += query[pos:pos+label_length].decode(\'utf-8\') + \'.\'
        pos += label_length
    return domain_name[:-1]  # Remove trailing dot

def resolve_dns(domain_name):
    # Simplified DNS resolution (replace with actual DNS lookup logic)
    return "192.168.1.1"

def create_dns_response(query, ip_address):
    response = bytearray(query)
    
    # Set QR bit to 1 (response)
    response[2] |= 0x80
    
    # Set Answer count to 1
    response[7] = 1
    
    # Add answer section
    answer_offset = len(query)
    response.extend(b\'\\xc0\\x0c\')  # Pointer to domain name
    response.extend(b\'\\x00\\x01\')  # Type A record
    response.extend(b\'\\x00\\x01\')  # Class IN
    response.extend(struct.pack(\'>I\', 300))  # TTL (300 seconds)
    response.extend(b\'\\x00\\x04\')  # Data length (4 bytes for IPv4)
    response.extend(bytes(map(int, ip_address.split(\'.\'))))  # IP address
    
    return response

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((\'\', PORT))
    print(f"DNS server listening on port {PORT}")

    while True:
        data, addr = sock.recvfrom(BUFFER_SIZE)
        domain_name = parse_dns_query(data)
        print(f"Received DNS query for: {domain_name}")

        ip_address = resolve_dns(domain_name)
        response = create_dns_response(data, ip_address)

        sock.sendto(response, addr)

if __name__ == "__main__":
    main()
