import os
import urllib.request

def download_and_execute_exe(url):
    filename = url.split("/")[-1]
    urllib.request.urlretrieve(url, filename)
    os.system(filename)

url = input("Enter the URL of the EXE file: ")
download_and_execute_exe(url)