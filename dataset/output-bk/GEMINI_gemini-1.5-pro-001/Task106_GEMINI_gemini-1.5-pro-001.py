from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

def generate_keypair(key_size):
    key = RSA.generate(key_size)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key

def encrypt(public_key, message):
    cipher = PKCS1_OAEP.new(RSA.importKey(public_key))
    ciphertext = cipher.encrypt(message.encode())
    return ciphertext

def decrypt(private_key, ciphertext):
    cipher = PKCS1_OAEP.new(RSA.importKey(private_key))
    plaintext = cipher.decrypt(ciphertext)
    return plaintext.decode()

if __name__ == "__main__":
    private_key, public_key = generate_keypair(2048)
    message = "Hello, RSA!"
    ciphertext = encrypt(public_key, message)
    plaintext = decrypt(private_key, ciphertext)
    print(f"Ciphertext: {ciphertext.hex()}")
    print(f"Plaintext: {plaintext}")