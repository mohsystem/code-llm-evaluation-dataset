import ipaddress

def validate_ip(ip):
    try:
        ipaddress.ip_address(ip)
        return True
    except ValueError:
        return False

# Test the function
print(validate_ip('192.168.1.1'))  # True
print(validate_ip('256.168.1.1'))  # False