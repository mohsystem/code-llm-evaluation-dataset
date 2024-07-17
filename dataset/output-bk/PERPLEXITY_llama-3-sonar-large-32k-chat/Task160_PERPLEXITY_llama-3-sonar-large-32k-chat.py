import requests

url = input("Enter a URL: ")
response = requests.get(url)

print("Status Code:", response.status_code)
print("Response Content:", response.text)