from Crypto.PublicKey import RSA

def generate_rsa_key():
    key = RSA.generate(2048)
    private_key = key.exportKey(format='PEM')
    return private_key.decode('ascii')

print(generate_rsa_key())