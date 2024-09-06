
import hashlib
import ssl
import socket

def get_certificate_hash(hostname, port=443):
    context = ssl.create_default_context()
    with socket.create_connection((hostname, port)) as sock:
        with context.wrap_socket(sock, server_hostname=hostname) as secure_sock:
            cert = secure_sock.getpeercert(binary_form=True)
    return hashlib.sha256(cert).hexdigest()

def check_certificate_hash(hostname, known_hash):
    try:
        cert_hash = get_certificate_hash(hostname)
        if cert_hash == known_hash:
            print(f"Certificate hash for {hostname} matches the known hash.")
        else:
            print(f"Certificate hash for {hostname} does not match the known hash.")
            print(f"Calculated hash: {cert_hash}")
            print(f"Known hash:     {known_hash}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    hostname = "www.example.com"
    known_hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"  # Example hash
    check_certificate_hash(hostname, known_hash)
