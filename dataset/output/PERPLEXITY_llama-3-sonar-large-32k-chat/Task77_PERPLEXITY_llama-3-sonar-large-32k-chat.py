import sys
from ftplib import FTP

ftp = FTP(sys.argv[1])
ftp.login(sys.argv[2], sys.argv[3])
ftp.retrbinary('RETR ' + sys.argv[4], open(sys.argv[4], 'wb').write)
ftp.quit()