import ftplib
import sys

def download_file(hostname, username, password, filename):
    ftp = ftplib.FTP(hostname)
    ftp.login(user=username, passwd=password)
    ftp.cwd('/')  # Change to the desired directory
    local_filename = filename
    with open(local_filename, 'wb') as file:
        ftp.retrbinary('RETR ' + filename, file.write)
    ftp.quit()

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print("Usage: python ftp_download.py <hostname> <username> <password> <filename>")
        sys.exit(1)

    hostname = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    filename = sys.argv[4]

    download_file(hostname, username, password, filename)