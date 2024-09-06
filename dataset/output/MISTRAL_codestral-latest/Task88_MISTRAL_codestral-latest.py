import os
import random
import string
import tempfile

def create_temp_file():
    # Create a temporary file
    temp = tempfile.NamedTemporaryFile(delete=False, mode='w', encoding='utf-8')

    # Generate a random string
    random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=10))

    # Convert the string to Unicode
    unicode_string = ''.join([format(ord(c), '04x') for c in random_string])

    # Write the Unicode string to the file
    temp.write(unicode_string)
    temp.close()

    # Return the path of the temporary file
    return temp.name

print(create_temp_file())