import sys
import requests
import re

if len(sys.argv) > 1:
    url = sys.argv[1]
    try:
        response = requests.get(url)
        if response.status_code == 200:
            html = response.text
            title_match = re.search(r'<title>(.*?)</title>', html)
            if title_match:
                print(title_match.group(1))
    except Exception as e:
        print(e)