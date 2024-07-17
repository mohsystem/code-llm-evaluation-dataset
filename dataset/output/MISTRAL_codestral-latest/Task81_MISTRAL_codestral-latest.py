import hashlib
from OpenSSL import crypto

def cert_hash_matches(cert_path, known_hash):
    with open(cert_path, 'rb') as f:
        cert = crypto.load_certificate(crypto.FILETYPE_PEM, f.read())

    der = crypto.dump_certificate(crypto.FILETYPE_ASN1, cert)
    calculated_hash = hashlib.sha256(der).hexdigest()

    return calculated_hash == known_hash

cert_path = "path_to_certificate.crt"
known_hash = "known_hash"

matches = cert_hash_matches(cert_path, known_hash)
print("Certificate hash matches known hash:", matches)