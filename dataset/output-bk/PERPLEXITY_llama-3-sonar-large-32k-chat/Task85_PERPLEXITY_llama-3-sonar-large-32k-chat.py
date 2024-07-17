import random
import string

def generate_random_string(length):
    alphabet = string.ascii_letters
    return ''.join(random.choice(alphabet) for _ in range(length))

print(generate_random_string(10))