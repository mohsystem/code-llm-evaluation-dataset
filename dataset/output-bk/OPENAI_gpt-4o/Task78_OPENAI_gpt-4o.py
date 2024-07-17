from Crypto.PublicKey import RSA

def generate_key():
    key = RSA.generate(2048)
    private_key = key.exportKey('PEM')
    with open("id_rsa_python.pem", "wb") as f:
        f.write(private_key)

generate_key()