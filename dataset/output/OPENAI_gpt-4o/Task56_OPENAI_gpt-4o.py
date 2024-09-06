import secrets
import time

token = secrets.token_hex(16)
print(f"Python Generated Token: {token}")
print("Waiting 5 seconds for next part...")

time.sleep(5)