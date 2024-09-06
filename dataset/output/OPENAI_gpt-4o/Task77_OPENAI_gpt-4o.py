import ftplib
import sys

if __name__ == '__main__':
    hostname = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    filename = sys.argv[4]

    ftp = ftplib.FTP(hostname)
    ftp.login(user=username, passwd=password)
    with open(filename, 'wb') as f:
        ftp.retrbinary('RETR ' + filename, f.write)
    ftp.quit()