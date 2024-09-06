
import random
import string

def generate_random_number(min_val, max_val):
    return random.randint(min_val, max_val)

def generate_random_token(length):
    characters = string.ascii_letters + string.digits
    return ''.join(random.choice(characters) for _ in range(length))

if __name__ == "__main__":
    print("Random number:", generate_random_number(1, 100))
    print("Random token:", generate_random_token(10))
