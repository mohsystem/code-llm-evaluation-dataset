
import random
import string

def generate_random_string(length):
    alphabet = string.ascii_letters
    return \'\'.join(random.choice(alphabet) for _ in range(length))

if __name__ == "__main__":
    length = 10
    random_string = generate_random_string(length)
    print(f"Random string: {random_string}")
