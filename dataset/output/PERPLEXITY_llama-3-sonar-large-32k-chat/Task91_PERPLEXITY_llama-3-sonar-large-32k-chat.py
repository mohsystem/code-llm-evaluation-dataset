import socket

def udp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(("localhost", 9876))

    while True:
        data, address = server_socket.recvfrom(1024)
        print("Received packet from", address)
        data = data.decode("utf-8").upper().encode("utf-8")
        server_socket.sendto(data, address)

if __name__ == "__main__":
    udp_server()