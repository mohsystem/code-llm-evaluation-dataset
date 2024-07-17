import ftplib
import sys

if __name__ == "__main__":
    ftp_server = sys.argv[1]
    username = sys.argv[2]
    password = sys.argv[3]
    filename = sys.argv[4]

    with ftplib.FTP(ftp_server, username, password) as ftp:
        ftp.cwd("/path/to/sensitive/files")
        with open(filename, "wb") as file:
            ftp.retrbinary(f"RETR {filename}", file.write)