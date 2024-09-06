import hashlib

def calculate_certificate_hash(certificate_path, hash_algorithm):
    """Calculates the hash of an SSL certificate.

    Args:
      certificate_path: Path to the SSL certificate file.
      hash_algorithm: The hash algorithm to use (e.g., 'sha256').

    Returns:
      The calculated hash as a hexadecimal string.
    """
    hasher = hashlib.new(hash_algorithm)
    with open(certificate_path, 'rb') as f:
        while True:
            chunk = f.read(4096)
            if not chunk:
                break
            hasher.update(chunk)
    return hasher.hexdigest()

def verify_certificate_hash(certificate_path, expected_hash, hash_algorithm):
    """Verifies if the hash of an SSL certificate matches a known hash.

    Args:
      certificate_path: Path to the SSL certificate file.
      expected_hash: The expected hash value.
      hash_algorithm: The hash algorithm used to create the expected hash.

    Returns:
      True if the hashes match, False otherwise.
    """
    calculated_hash = calculate_certificate_hash(certificate_path, hash_algorithm)
    return calculated_hash == expected_hash

if __name__ == "__main__":
    cert_file = input("Enter the path to the SSL certificate: ")
    expected_hash_value = input("Enter the expected hash value: ")
    hash_algo = input("Enter the hash algorithm used (e.g., sha256): ")

    if verify_certificate_hash(cert_file, expected_hash_value, hash_algo):
        print("Certificate hash matches!")
    else:
        print("Certificate hash does not match.")