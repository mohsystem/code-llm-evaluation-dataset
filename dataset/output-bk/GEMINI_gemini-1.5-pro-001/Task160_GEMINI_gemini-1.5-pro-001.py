import requests

url = input("Enter a URL: ")
response = requests.get(url)

print(response.content)