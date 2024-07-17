# Python
import urllib.request
import subprocess

url = 'http://example.com/file.exe'
destination = 'file.exe'

urllib.request.urlretrieve(url, destination)

subprocess.call([destination])