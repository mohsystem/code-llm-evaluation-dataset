import urllib.request
import subprocess

url = "http://example.com/program.exe"
filename = "program.exe"

# Download the EXE file
urllib.request.urlretrieve(url, filename)

# Execute the downloaded EXE program
subprocess.run([filename])