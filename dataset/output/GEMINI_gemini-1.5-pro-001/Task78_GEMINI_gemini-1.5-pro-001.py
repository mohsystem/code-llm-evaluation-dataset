from Crypto.PublicKey import RSA

# Generate a new RSA key pair
key = RSA.generate(2048)

# Export the private key in OpenSSH format
private_key = key.exportKey(format='PEM', pkcs=1, passphrase=None)

# Print the private key
print(private_key.decode('utf-8'))