
import base64

def encrypt(data):
    return base64.b64encode(data.encode()).decode()

def decrypt(encoded_data):
    return base64.b64decode(encoded_data.encode()).decode()

sensitive_data = {
    "credit_card": "1234-5678-9012-3456",
    "ssn": "123-45-6789",
    "password": "mySecretPass123"
}

encrypted_data = {key: encrypt(value) for key, value in sensitive_data.items()}

print("Encrypted data:", encrypted_data)

decrypted_data = {key: decrypt(value) for key, value in encrypted_data.items()}

print("Decrypted data:", decrypted_data)
