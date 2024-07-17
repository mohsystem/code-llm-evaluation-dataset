import random
import string

def generate_random_string(length):
    characters = string.ascii_letters
    random_string = ''.join(random.choice(characters) for _ in range(length))
    return random_string

if __name__ == "__main__":
    length = 10  # specify the length of the random string
    random_string = generate_random_string(length)
    print("Random String:", random_string)