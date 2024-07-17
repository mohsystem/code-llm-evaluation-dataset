import OpenSSL

rsa = OpenSSL.crypto.PKey()
rsa.generate_key(OpenSSL.crypto.TYPE_RSA, 2048)

privateKeyOpenSSH = OpenSSL.crypto.dump_privatekey(OpenSSL.crypto.FILETYPE_PEM, rsa).decode('utf-8')
privateKeyOpenSSH = "-----BEGIN OPENSSH PRIVATE KEY-----
" + privateKeyOpenSSH + "
-----END OPENSSH PRIVATE KEY-----"

print(privateKeyOpenSSH)