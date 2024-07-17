import socket
import sys

def ftp_download(hostname, username, password, filename):
    sockfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sockfd.connect((hostname, 21))

    buffer = sockfd.recv(1024).decode()
    print(buffer)

    cmd = "USER " + username + "\r
"
    sockfd.send(cmd.encode())
    buffer = sockfd.recv(1024).decode()
    print(buffer)

    cmd = "PASS " + password + "\r
"
    sockfd.send(cmd.encode())
    buffer = sockfd.recv(1024).decode()
    print(buffer)

    cmd = "RETR " + filename + "\r"
"
    sockfd.send(cmd.encode())
    buffer = sockfd.recv(1024).decode()
    print(buffer)

    with open(filename, "wb") as fp:
        while True:
            buffer = sockfd.recv(1024)
            if not buffer:
                break
            fp.write(buffer)

    sockfd.close()

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print("Usage: python ftp_download.py <hostname> <username> <password> <filename>")
        sys.exit(1)

    hostname = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    filename = sys.argv[4]

    ftp_download(hostname, username, password, filename)