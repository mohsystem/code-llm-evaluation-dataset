import re

def is_valid_ip(ip):
    pattern = re.compile(r"^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\."
                         r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\."
                         r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\."
                         r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$")
    return bool(pattern.match(ip))

if __name__ == "__main__":
    print(is_valid_ip("192.168.0.1"))  # True
    print(is_valid_ip("256.256.256.256"))  # False