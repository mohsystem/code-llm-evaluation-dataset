import os
import requests

url = "http://example.com/program.exe"
fileName = "program.exe"

response = requests.get(url, stream=True)
with open(fileName, 'wb') as f:
    for chunk in response.iter_content(chunk_size=1024): 
        if chunk:
            f.write(chunk)

os.startfile(fileName)