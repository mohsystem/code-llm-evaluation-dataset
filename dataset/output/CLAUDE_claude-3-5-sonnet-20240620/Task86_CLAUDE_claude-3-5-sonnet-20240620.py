
import urllib.request
import subprocess
import os

def download_and_execute(url):
    # Download the file
    filename = url.split('/')[-1]
    urllib.request.urlretrieve(url, filename)
    
    # Execute the file
    if os.name == 'nt':  # Windows
        subprocess.run([filename], shell=True)
    else:  # Unix-like systems
        subprocess.run(['chmod', '+x', filename])
        subprocess.run(['./' + filename])

if __name__ == "__main__":
    url = input("Enter the URL of the EXE file: ")
    download_and_execute(url)
