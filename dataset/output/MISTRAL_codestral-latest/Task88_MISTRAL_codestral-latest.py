# Python
import os
import random
import string

def generate_random_string(length):
    letters = string.ascii_letters + string.digits
    return ''.join(random.choice(letters) for i in range(length))

random_string = generate_random_string(10)
with open("temp.txt", "w", encoding="utf-8") as temp_file:
    temp_file.write(random_string)
print(os.path.abspath("temp.txt"))