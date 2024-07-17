
import requests

url = input("Enter a URL: ")
try:
    response = requests.get(url)
    print(f"Status code: {response.status_code}")
    print("Response content:")
    print(response.text)
except requests.exceptions.RequestException as e:
    print(f"An error occurred: {e}")
