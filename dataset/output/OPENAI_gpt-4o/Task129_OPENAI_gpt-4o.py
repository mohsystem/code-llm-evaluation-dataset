import requests

def fetch_file(file_name):
    url = f"http://example.com/{file_name}"
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    else:
        return f"Failed to retrieve file: {response.status_code}"

file_name = input("Enter file name: ")
file_content = fetch_file(file_name)
print(file_content)