import re

def validate_url(url):
    """
    Validates a URL using a regular expression.

    Args:
        url: The URL to validate.

    Returns:
        True if the URL is valid, False otherwise.
    """
    regex = re.compile(
        r"^(http|https)://([a-z0-9]+(-[a-z0-9]+)*\.)+[a-z]{2,6}(:[0-9]+)?(/.*)?$"
    )
    match = regex.match(url)
    return bool(match)

if __name__ == "__main__":
    url = input("Enter a URL to validate: ")
    if validate_url(url):
        print(f"{url} is a valid URL.")
    else:
        print(f"{url} is not a valid URL.")