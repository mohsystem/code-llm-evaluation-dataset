import random

def generate_random_token(length):
    token = ''.join(random.choices('ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789', k=length))
    return token

print(generate_random_token(10))