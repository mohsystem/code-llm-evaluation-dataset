import re

def is_valid_ip(ip):
  """
  Validates an IP address.

  Args:
    ip: The IP address to validate.

  Returns:
    True if the IP address is valid, False otherwise.
  """
  regex = "^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$"
  return re.match(regex, ip) is not None

# Get user input
ip_address = input("Enter an IP address: ")

# Validate the IP address
if is_valid_ip(ip_address):
  print("Valid IP address")
else:
  print("Invalid IP address")