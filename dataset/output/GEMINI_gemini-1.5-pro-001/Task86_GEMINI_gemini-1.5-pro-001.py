import requests
import os

def download_and_run_exe(url):
    try:
        response = requests.get(url)
        response.raise_for_status()

        with open("downloaded_file.exe", "wb") as f:
            f.write(response.content)

        os.system("downloaded_file.exe")

    except requests.exceptions.RequestException as e:
        print(f"An error occurred while downloading the file: {e}")

    except OSError as e:
        print(f"An error occurred while executing the file: {e}")

if __name__ == "__main__":
    url = input("Enter the URL of the EXE file: ")
    download_and_run_exe(url)