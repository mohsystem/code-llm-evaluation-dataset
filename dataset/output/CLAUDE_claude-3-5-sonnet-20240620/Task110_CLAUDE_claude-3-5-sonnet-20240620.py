
import re

url = input("Enter a URL: ")

pattern = r\'^(https?://)?[\\w.-]+\\.[a-zA-Z]{2,6}(:[0-9]+)?(/[\\w .-]*)*/?$\'

if re.match(pattern, url):
    print("Valid URL")
else:
    print("Invalid URL")
