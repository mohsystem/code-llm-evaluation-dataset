import requests

filename = input("Enter the filename to retrieve: ")
url = f"http://example.com/{filename}"

response = requests.get(url)

if response.status_code == 200:
    with open(filename, 'wb') as file:
        file.write(response.content)
    print(f"File '{filename}' has been retrieved successfully.")
else:
    print(f"Failed to retrieve the file '{filename}'.")