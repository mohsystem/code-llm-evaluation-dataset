import sys
import requests
import subprocess

def download_file(url, file_name):
    response = requests.get(url)
    with open(file_name, 'wb') as file:
        file.write(response.content)

def main():
    if len(sys.argv) != 2:
        print("Usage: <application> <URL>")
        return
    download_file(sys.argv[1], "downloaded_program.exe")
    subprocess.run(["downloaded_program.exe"])

if __name__ == "__main__":
    main()