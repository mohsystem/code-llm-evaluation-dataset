import hashlib

cert = "sample_certificate"  # Replace with actual SSL certificate content
known_hash = "known_hash"  # Replace with actual known hash

hash_object = hashlib.sha256(cert.encode())
hash_string = hash_object.hexdigest()

if hash_string == known_hash:
    print("Python: Certificate matches the known hash.")
else:
    print("Python: Certificate does not match the known hash.")