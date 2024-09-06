import re

def validate_ip(ip):
    pattern = r'^(\d{1,3}\.){3}\d{1,3}$'
    if not re.match(pattern, ip):
        return False
    parts = ip.split('.')
    for part in parts:
        if int(part) < 0 or int(part) > 255:
            return False
    return True

ips = ["192.168.1.1", "256.256.256.256", "123.045.067.089"]
validated_ips = [ip for ip in ips if validate_ip(ip)]
print("Validated IPs:", validated_ips)