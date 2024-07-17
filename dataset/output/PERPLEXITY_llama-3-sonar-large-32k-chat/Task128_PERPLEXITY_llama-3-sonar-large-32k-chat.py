import random
import string

def generate_token(length):
    letters_and_digits = string.ascii_letters + string.digits
    result_str = ''.join(random.choice(letters_and_digits) for i in range(length))
    print("Random token is ", result_str)

generate_token(10)