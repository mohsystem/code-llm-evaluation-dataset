import requests

def main():
    url = input("Enter a URL: ")
    response = requests.get(url)
    if response.status_code == 200:
        print(response.text)
    else:
        print("GET request failed")

if __name__ == "__main__":
    main()