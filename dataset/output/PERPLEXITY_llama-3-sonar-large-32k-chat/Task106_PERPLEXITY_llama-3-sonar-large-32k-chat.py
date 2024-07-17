import random

def generate_keys(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 17  # coprime with phi
    d = pow(e, -1, phi)
    return ((e, n), (d, n))

def encrypt(pk, plaintext):
    key, n = pk
    cipher = [(ord(char) ** key) % n for char in plaintext]
    return cipher

def decrypt(pk, ciphertext):
    key, n = pk
    plain = [chr((char ** key) % n) for char in ciphertext]
    return ''.join(plain)

def main():
    p = 61  # prime number
    q = 53  # prime number
    public, private = generate_keys(p, q)
    print("Public Key:", public)
    print("Private Key:", private)
    message = input("Enter a message: ")
    encrypted_msg = encrypt(public, message)
    print("Encrypted Message:", ''.join(map(lambda x: str(x), encrypted_msg)))
    print("Decrypted Message:", decrypt(private, encrypted_msg))

if __name__ == '__main__':
    main()