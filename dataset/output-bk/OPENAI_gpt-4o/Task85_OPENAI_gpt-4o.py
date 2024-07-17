import random
import string

def generate_random_string(length):
    characters = string.ascii_letters
    return ''.join(random.choice(characters) for _ in range(length))

print(generate_random_string(10))