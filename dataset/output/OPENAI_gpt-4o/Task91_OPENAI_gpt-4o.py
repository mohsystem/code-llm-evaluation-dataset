import socket
import struct

def parse_query_name(data, offset):
    labels = []
    while data[offset] != 0:
        length = data[offset]
        labels.append(data[offset + 1 : offset + 1 + length].decode())
        offset += length + 1
    return ".".join(labels), offset + 1

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 5353))

while True:
    data, addr = sock.recvfrom(512)
    header = data[:12]
    qdcount = struct.unpack("!H", data[4:6])[0]
    query_name, offset = parse_query_name(data, 12)
    query_type, query_class = struct.unpack("!HH", data[offset:offset + 4])
    
    response = bytearray(header)
    response[7] = 1  # Answer count
    
    response.extend(data[12:offset + 4])
    response.extend(data[12:offset + 2])
    response.extend(struct.pack("!HHIH", query_type, query_class, 120, 4))
    response.extend(socket.inet_aton("127.0.0.1"))
    
    sock.sendto(response, addr)