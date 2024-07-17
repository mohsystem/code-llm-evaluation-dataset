import re

def validate_url(url):
    url_regex = re.compile(r"^((https?|ftp|file)://)?(-\w+\.){1,}(com|org|net|gov|mil|biz|info|mobi|name|aero|jobs|edu|co\.uk|ac\.uk|gov\.uk|mil\.uk|nhs\.uk|police\.uk|mod\.uk|travel|local|me\.uk|ltd\.uk|plc\.uk|net\.uk|sch\.uk)(:\d+)?(/([\w\-\.\\\?\\,\\+&%*#=]*)?)?$")
    if url_regex.match(url):
        return True
    else:
        return False

url = input("Enter a URL: ")
if validate_url(url):
    print("URL is valid")
else:
    print("URL is not valid")