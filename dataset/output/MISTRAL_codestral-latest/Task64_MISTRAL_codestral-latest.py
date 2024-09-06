import json
import urllib.request

def read_json_from_url(url):
    response = urllib.request.urlopen(url)
    data = response.read()
    json_data = json.loads(data)
    return json_data