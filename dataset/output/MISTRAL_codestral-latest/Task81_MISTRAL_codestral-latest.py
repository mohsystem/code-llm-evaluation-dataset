import ssl
import hashlib

def check_ssl_certificate(host, port, known_hash):
    ctx = ssl.create_default_context()
    with ctx.wrap_socket(ssl.create_connection((host, port)), server_hostname=host) as s:
        cert = s.getpeercert(binary_form=True)
        cert_hash = hashlib.sha256(cert).hexdigest()
        return cert_hash == known_hash

# Example usage
host = 'example.com'
port = 443
known_hash = '...'  # Replace with the known hash
print(check_ssl_certificate(host, port, known_hash))