def validate_ip(ip):
    parts = ip.split(".")
    if len(parts) != 4:
        return False
    for part in parts:
        if not part.isdigit():
            return False
        if int(part) > 255 or int(part) < 0:
            return False
    return True

ip = input("Enter an IP address: ")
if validate_ip(ip):
    print("IP address is valid")
else:
    print("IP address is not valid")