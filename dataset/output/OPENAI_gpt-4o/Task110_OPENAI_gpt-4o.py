import re

def is_valid_url(url):
    regex = re.compile(r"^(http|https|ftp)://[^\s/$.?#].[^\s]*$")
    return re.match(regex, url) is not None

urls = [
    "http://example.com",
    "https://example.com",
    "ftp://example.com",
    "invalidurl.com"
]

for url in urls:
    print(f"{url} is {'valid' if is_valid_url(url) else 'invalid'}")
