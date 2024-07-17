import ftplib
import sys

def main():
    if len(sys.argv) < 5:
        print("Usage: {} <hostname> <username> <password> <file>".format(sys.argv[0]))
        return

    server = sys.argv[1]
    user = sys.argv[2]
    password = sys.argv[3]
    file = sys.argv[4]

    ftp = ftplib.FTP(server)
    ftp.login(user, password)
    ftp.cwd('/')

    with open(file, 'wb') as f:
        ftp.retrbinary('RETR ' + file, f.write)

    ftp.quit()

if __name__ == "__main__":
    main()