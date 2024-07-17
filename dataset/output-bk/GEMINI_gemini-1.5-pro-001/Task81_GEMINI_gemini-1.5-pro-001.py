import hashlib

def check_certificate_hash(certificate_path, expected_hash):
  """Checks if the hash of a certificate matches a known hash.

  Args:
    certificate_path: Path to the SSL certificate file.
    expected_hash: The expected hash value as a string.

  Returns:
    True if the hashes match, False otherwise.
  """
  try:
    with open(certificate_path, 'rb') as f:
      certificate_data = f.read()
    calculated_hash = hashlib.sha256(certificate_data).hexdigest()
    return calculated_hash == expected_hash
  except FileNotFoundError:
    print(f"Error: Certificate file not found at '{certificate_path}'")
    return False

if __name__ == "__main__":
  certificate_file = input("Enter the path to the SSL certificate file: ")
  expected_hash_value = input("Enter the expected SHA-256 hash: ")

  if check_certificate_hash(certificate_file, expected_hash_value):
    print("Certificate hash matches!")
  else:
    print("Certificate hash does not match.")