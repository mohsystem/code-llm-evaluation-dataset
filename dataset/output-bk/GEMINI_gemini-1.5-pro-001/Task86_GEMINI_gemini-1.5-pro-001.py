import requests
import os
import subprocess

def download_and_run(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Raise an exception for bad status codes

        filename = url.split("/")[-1]
        with open(filename, 'wb') as f:
            f.write(response.content)

        subprocess.Popen(filename)
    except requests.exceptions.RequestException as e:
        print(f"An error occurred while downloading the file: {e}")
    except OSError as e:
        print(f"An error occurred while running the file: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Please provide a URL as an argument.")
    else:
        url = sys.argv[1]
        download_and_run(url)