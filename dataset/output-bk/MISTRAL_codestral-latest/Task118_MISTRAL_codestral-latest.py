import re

def is_valid_ip(ip):
    pattern = r"^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\." \
              r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\." \
              r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\." \
              r"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"
    return bool(re.match(pattern, ip))

if __name__ == "__main__":
    ip = "192.168.1.1"
    if is_valid_ip(ip):
        print(f"{ip} is a valid IP address.")
    else:
        print(f"{ip} is not a valid IP address.")