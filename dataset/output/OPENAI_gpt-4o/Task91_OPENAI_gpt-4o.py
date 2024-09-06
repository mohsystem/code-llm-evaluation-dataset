# Python code for UDP DNS resolver (simplified)

import socket

def serve_dns():
    ip, port = "127.0.0.1", 5353
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((ip, port))
    
    while True:
        data, addr = sock.recvfrom(512)
        # Here you'd parse DNS request and handle it. Simplified example:
        response = data  # Echoing back the data for simplicity
        sock.sendto(response, addr)

if __name__ == "__main__":
    serve_dns()