
import hashlib
import ssl
import OpenSSL.crypto

def check_certificate_hash(cert_path, known_hash):
    with open(cert_path, \'rb\') as cert_file:
        cert_data = cert_file.read()

    cert = OpenSSL.crypto.load_certificate(OpenSSL.crypto.FILETYPE_PEM, cert_data)
    cert_der = OpenSSL.crypto.dump_certificate(OpenSSL.crypto.FILETYPE_ASN1, cert)

    calculated_hash = hashlib.sha256(cert_der).hexdigest()

    if calculated_hash == known_hash:
        print("Certificate hash matches the known hash.")
    else:
        print("Certificate hash does not match the known hash.")

if __name__ == "__main__":
    cert_path = "path/to/certificate.crt"
    known_hash = "known_hash_value"
    check_certificate_hash(cert_path, known_hash)
