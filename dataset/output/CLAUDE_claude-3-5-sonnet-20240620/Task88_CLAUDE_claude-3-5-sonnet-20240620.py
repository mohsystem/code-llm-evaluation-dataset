
import tempfile
import random
import string

def generate_random_string(length):
    return \'\'.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))

def convert_to_unicode(input_string):
    return \'\'.join(f\'\\\\u{ord(c):04x}\' for c in input_string)

# Create a temporary file
with tempfile.NamedTemporaryFile(prefix=\'unicode_\', suffix=\'.txt\', delete=False, mode=\'w\', encoding=\'utf-8\') as temp_file:
    # Generate a random string
    random_string = generate_random_string(10)
    
    # Convert the string to Unicode
    unicode_string = convert_to_unicode(random_string)
    
    # Write the Unicode string to the file
    temp_file.write(unicode_string)

    # Get the path of the temporary file
    temp_file_path = temp_file.name

# Print the path of the temporary file
print(f"Temporary file path: {temp_file_path}")
