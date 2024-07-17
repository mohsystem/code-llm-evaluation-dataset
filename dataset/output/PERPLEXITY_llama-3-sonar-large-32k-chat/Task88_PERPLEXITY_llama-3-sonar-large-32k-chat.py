import os
import random
import string
import tempfile

def generate_random_string(length=10):
    chars = string.ascii_letters
    return ''.join(random.choice(chars) for _ in range(length))

def to_unicode(s):
    return ''.join('\\u{:04x}'.format(ord(c)) for c in s)

def write_to_file(file_path, content):
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(content)

def main():
    with tempfile.NamedTemporaryFile(suffix='.txt', delete=False) as f:
        random_string = generate_random_string()
        unicode_string = to_unicode(random_string)
        write_to_file(f.name, unicode_string)
        print(f.name)

if __name__ == '__main__':
    main()