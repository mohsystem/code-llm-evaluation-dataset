import random

def generate_random_string(length):
    letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return ''.join(random.choice(letters) for _ in range(length))

if __name__ == "__main__":
    length = 10  # Specify the desired length of the random string
    random_string = generate_random_string(length)
    print(random_string)