
import random
import string

def generate_random_number():
    return random.randint(1, 100)

def generate_random_token():
    return \'\'.join(random.choices(string.ascii_letters + string.digits, k=8))

print("Random Number:", generate_random_number())
print("Random Token:", generate_random_token())
