from Crypto.Util.number import getPrime, bytes_to_long, long_to_bytes
from Crypto.PublicKey import RSA

def rsa_init():
    p = getPrime(1024)
    q = getPrime(1024)
    N = p * q
    phi = (p - 1) * (q - 1)
    e = getPrime(1024 // 2)
    while gcd(phi, e) > 1 and e < phi:
        e = getPrime(1024 // 2)
    d = pow(e, -1, phi)
    return (N, e), (N, d)

def rsa_encrypt(message, public_key):
    N, e = public_key
    return pow(bytes_to_long(message), e, N)

def rsa_decrypt(encrypted, private_key):
    N, d = private_key
    return long_to_bytes(pow(encrypted, d, N))