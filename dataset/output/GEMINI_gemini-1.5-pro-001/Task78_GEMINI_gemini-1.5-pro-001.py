from Crypto.PublicKey import RSA
from Crypto.Util import number

# Generate a new RSA key
key = RSA.generate(2048, number.getPrime)

# Export the private key in OpenSSH format
private_key = key.export_key(format='OpenSSH')

# Print the private key
print(private_key.decode('utf-8'))