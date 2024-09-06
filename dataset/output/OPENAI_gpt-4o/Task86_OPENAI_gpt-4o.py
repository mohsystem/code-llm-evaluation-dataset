import requests
import subprocess

url = "http://example.com/program.exe"
response = requests.get(url)
exe_path = "downloaded_program.exe"
with open(exe_path, "wb") as f:
    f.write(response.content)
subprocess.run(exe_path)