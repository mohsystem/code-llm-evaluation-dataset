import hashlib
import OpenSSL

known_hash = "your_known_hash_here"
certificate_path = "path_to_your_certificate.cer"

with open(certificate_path, 'rb') as file:
    cert = OpenSSL.crypto.load_certificate(OpenSSL.crypto.FILETYPE_PEM, file.read())

hash = hashlib.sha256(cert.to_cryptography().public_bytes(encoding='der')).hexdigest()

if hash == known_hash:
    print("Certificate matches the known hash.")
else:
    print("Certificate does not match the known hash.")