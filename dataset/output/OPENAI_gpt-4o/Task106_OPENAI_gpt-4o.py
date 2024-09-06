# Python RSA Encryption and Decryption
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

key = RSA.generate(2048)
private_key = key.export_key()
public_key = key.publickey().export_key()

print(f"Public Key:  {public_key.decode('utf-8')}")
print(f"Private Key: {private_key.decode('utf-8')}")

message = 'This is a secret message'
encryptor = PKCS1_OAEP.new(RSA.importKey(public_key))
encrypted = encryptor.encrypt(message.encode('utf-8'))
print(f"Encrypted: {binascii.hexlify(encrypted)}")

decryptor = PKCS1_OAEP.new(RSA.importKey(private_key))
decrypted = decryptor.decrypt(encrypted).decode('utf-8')
print(f"Decrypted: {decrypted}")