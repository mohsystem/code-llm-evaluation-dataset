import re

def is_valid_url(url):
    url_pattern = re.compile(
        r'^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]$'
    )
    return url_pattern.match(url) is not None

url = "http://www.example.com"
if is_valid_url(url):
    print("URL is valid")
else:
    print("URL is not valid")