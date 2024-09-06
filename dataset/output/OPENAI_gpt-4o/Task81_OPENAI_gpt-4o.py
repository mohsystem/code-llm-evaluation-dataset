import hashlib
import ssl

def get_cert_hash(cert_path):
    with open(cert_path, "rb") as cert_file:
        cert_data = cert_file.read()
    cert = ssl.DER_cert_to_PEM_cert(cert_data)
    cert_hash = hashlib.sha256(cert.encode('utf-8')).hexdigest()
    return cert_hash

def main():
    known_hash = "your_known_hash_here"
    cert_path = "path_to_your_certificate.crt"
    cert_hash = get_cert_hash(cert_path)
    
    if cert_hash == known_hash:
        print("Certificate matches the known hash.")
    else:
        print("Certificate does not match the known hash.")

if __name__ == "__main__":
    main()