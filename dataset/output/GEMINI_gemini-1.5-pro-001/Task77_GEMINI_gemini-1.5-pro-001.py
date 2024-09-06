import ftplib
import sys

if len(sys.argv) != 5:
    print("Usage: ftp_downloader.py <hostname> <username> <password> <remote_filename>")
    sys.exit(1)

hostname, username, password, remote_filename = sys.argv[1:]

with ftplib.FTP(hostname, username, password) as ftp:
    with open(remote_filename, 'wb') as local_file:
        ftp.retrbinary('RETR ' + remote_filename, local_file.write)

print(f"File '{remote_filename}' downloaded successfully.")