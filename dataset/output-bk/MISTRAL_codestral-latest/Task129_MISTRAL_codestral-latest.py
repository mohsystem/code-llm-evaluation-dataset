import urllib.request

def download_file(url, file_name):
    urllib.request.urlretrieve(url, file_name)

file_name = input("Enter the file name: ")
url = f"http://example.com/{file_name}"
download_file(url, file_name)