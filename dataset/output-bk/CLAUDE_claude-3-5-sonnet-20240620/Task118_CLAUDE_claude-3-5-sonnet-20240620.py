
import re

def is_valid_ipv4(ip):
    octets = ip.split(\'.\')
    if len(octets) != 4:
        return False
    for octet in octets:
        if not octet.isdigit() or len(octet) > 3 or int(octet) < 0 or int(octet) > 255:
            return False
        if octet[0] == \'0\' and len(octet) > 1:
            return False
    return True

def is_valid_ipv6(ip):
    pattern = r\'^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$\'
    return bool(re.match(pattern, ip))

if __name__ == "__main__":
    ip = input("Enter an IP address: ")
    
    if is_valid_ipv4(ip):
        print("Valid IPv4 address")
    elif is_valid_ipv6(ip):
        print("Valid IPv6 address")
    else:
        print("Invalid IP address")
