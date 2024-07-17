import os
import random
import string
import tempfile

def generate_random_string(length):
    return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))

def convert_to_unicode(text):
    return ''.join(f'\\u{ord(c):04x}' for c in text)

def main():
    with tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', delete=False) as f:
        random_string = generate_random_string(10)
        unicode_string = convert_to_unicode(random_string)
        f.write(unicode_string)
        temp_file_path = f.name
    print(temp_file_path)

if __name__ == "__main__":
    main()