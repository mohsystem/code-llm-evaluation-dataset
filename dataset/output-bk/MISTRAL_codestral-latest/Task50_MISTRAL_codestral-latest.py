# Python
import socket

def main():
    server_socket = socket.socket()
    server_socket.bind(('0.0.0.0', 1234))
    server_socket.listen(2)
    conn, addr = server_socket.accept()

    with open('uploadedFile.txt', 'wb') as f:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            f.write(data)

    print('File transfer successful.')

if __name__ == "__main__":
    main()