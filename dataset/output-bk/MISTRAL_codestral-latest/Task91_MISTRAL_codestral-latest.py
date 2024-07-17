import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('0.0.0.0', 53))

while True:
    data, addr = sock.recvfrom(512)
    request = data.decode('utf-8')
    # Parse the request, resolve DNS records, and send the response