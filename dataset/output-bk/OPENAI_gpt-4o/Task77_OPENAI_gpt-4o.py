import sys
from ftplib import FTP

def download_file(hostname, username, password, remote_file):
    ftp = FTP(hostname)
    ftp.login(user=username, passwd=password)
    local_filename = remote_file.split('/')[-1]

    with open(local_filename, 'wb') as local_file:
        ftp.retrbinary('RETR ' + remote_file, local_file.write)

    ftp.quit()
    print("File has been downloaded successfully.")

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("Usage: python script.py <hostname> <username> <password> <remoteFilePath>")
        sys.exit(1)
    
    hostname = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    remote_file = sys.argv[4]
    
    download_file(hostname, username, password, remote_file)