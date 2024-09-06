import re

def is_valid_url(url):
  """
  Checks if a given URL is valid using a regular expression.

  Args:
    url: The URL to validate.

  Returns:
    True if the URL is valid, False otherwise.
  """
  regex = re.compile(
      r'^(?:http|ftp)s?://'  # http:// or https://
      r'(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\.)+(?:[A-Z]{2,6}\.?|[A-Z0-9-]{2,}\.?)|'  # domain...
      r'localhost|'  # localhost...
      r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'  # ...or ip
      r'(?::\d+)?'  # optional port
      r'(?:/?|[/?]\S+)$', re.IGNORECASE)
  return re.match(regex, url) is not None

if __name__ == '__main__':
  url = input("Enter a URL: ")
  if is_valid_url(url):
    print("Valid URL")
  else:
    print("Invalid URL")