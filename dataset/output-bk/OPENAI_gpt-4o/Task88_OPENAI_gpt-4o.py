import os
import tempfile
import random
import string

# Generate random string
random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=7))

# Convert to Unicode (In Python3, str are Unicode by default)
unicode_string = random_string

# Create temporary file
temp_file = tempfile.NamedTemporaryFile(delete=False, suffix='.txt')
temp_file.write(unicode_string.encode('utf-8'))
temp_file_path = temp_file.name
temp_file.close()

# Return the path
print(f"File path: {temp_file_path}")