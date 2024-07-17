import ipaddress

def validateIP(ip):
    try:
        ipaddress.IPv4Address(ip)
        return True
    except ValueError:
        return False

ip = input("Enter an IP address: ")
if validateIP(ip):
    print("IP address is valid")
else:
    print("IP address is not valid")