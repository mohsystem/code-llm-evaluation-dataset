from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

key = RSA.generate(2048)
private_key = key.export_key()
public_key = key.publickey().export_key()

message = b'Hello RSA!'
print(f'Plaintext: {message.decode()}')

cipher = PKCS1_OAEP.new(key.publickey())
ciphertext = cipher.encrypt(message)
print(f'Encrypted: {ciphertext}')

decipher = PKCS1_OAEP.new(key)
decrypted_message = decipher.decrypt(ciphertext)
print(f'Decrypted: {decrypted_message.decode()}')