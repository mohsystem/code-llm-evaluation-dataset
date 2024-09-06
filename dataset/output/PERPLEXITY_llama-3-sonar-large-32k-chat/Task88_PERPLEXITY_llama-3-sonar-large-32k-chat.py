import os
import tempfile
import random
import string

def create_temp_file():
    temp = tempfile.NamedTemporaryFile(delete=False, encoding='utf-8')
    random_string = ''.join(random.choice(string.ascii_letters) for _ in range(10))
    unicode_string = random_string.encode('unicode-escape').decode('ascii')
    temp.write(unicode_string)
    temp.close()
    return temp.name

print(create_temp_file())