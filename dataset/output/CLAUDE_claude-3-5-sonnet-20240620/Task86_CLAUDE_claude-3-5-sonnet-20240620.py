
import sys
import requests
import subprocess

def download_and_execute(url):
    filename = "downloaded.exe"
    
    # Download the file
    response = requests.get(url)
    if response.status_code == 200:
        with open(filename, \'wb\') as file:
            file.write(response.content)
    else:
        print(f"Failed to download file. Status code: {response.status_code}")
        return

    # Execute the file
    try:
        subprocess.run([filename], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error executing file: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <URL>")
    else:
        download_and_execute(sys.argv[1])
