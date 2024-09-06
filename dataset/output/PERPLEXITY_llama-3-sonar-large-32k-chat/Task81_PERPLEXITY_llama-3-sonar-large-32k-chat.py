import hashlib
import ssl

def check_ssl_certificate(hostname, port, expected_hash):
    context = ssl.create_default_context()
    with context.wrap_socket(socket.create_connection((hostname, port)), server_hostname=hostname) as s:
        der_cert = s.getpeercert(binary_form=True)
        pem_cert = ssl.DER_cert_to_PEM_cert(der_cert)
        cert_hash = hashlib.sha256(pem_cert.encode()).hexdigest()
        if cert_hash == expected_hash:
            print("Certificate matches the expected hash")
        else:
            print("Certificate does not match the expected hash")

# Example usage:
check_ssl_certificate("example.com", 443, "expected_hash_here")