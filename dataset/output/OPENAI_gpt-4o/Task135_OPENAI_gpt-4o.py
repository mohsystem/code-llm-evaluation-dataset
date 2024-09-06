import hashlib
import os

class CSRFProtection:
    def __init__(self):
        self.token = None

    def generate_token(self, session_id):
        self.token = hashlib.sha256(os.urandom(60)).hexdigest() + session_id
        return self.token

    def validate_token(self, token, session_id):
        return token == self.token + session_id

csrf = CSRFProtection()
session_id = "12345ABC"
token = csrf.generate_token(session_id)
print("Token:", token)
print("Validation:", csrf.validate_token(token, session_id))