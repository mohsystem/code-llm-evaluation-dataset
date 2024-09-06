
import re

def validate_ip(ip):
    pattern = r'^(\\d{1,3}\\.){3}\\d{1,3}$'
    if not re.match(pattern, ip):
        return False
    octets = ip.split('.')
    return all(0 <= int(octet) <= 255 for octet in octets)

def process_ip(ip):
    if validate_ip(ip):
        octets = ip.split('.')
        class_type = ''
        if 1 <= int(octets[0]) <= 126:
            class_type = 'A'
        elif 128 <= int(octets[0]) <= 191:
            class_type = 'B'
        elif 192 <= int(octets[0]) <= 223:
            class_type = 'C'
        elif 224 <= int(octets[0]) <= 239:
            class_type = 'D'
        elif 240 <= int(octets[0]) <= 255:
            class_type = 'E'
        print(f"Valid IP address. Class: {class_type}")
    else:
        print("Invalid IP address")

if __name__ == "__main__":
    ip = input("Enter an IP address: ")
    process_ip(ip)
