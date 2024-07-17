import hashlib
import base64

password = "mypassword"
salt = "mysalt"
combined = password + salt
hash_bytes = hashlib.sha256(combined.encode()).digest()
hash = base64.b64encode(hash_bytes).decode()
print("Hash:", hash)