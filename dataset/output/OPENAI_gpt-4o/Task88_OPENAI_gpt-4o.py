import tempfile
import os
import random
import string

# Generate a random string
random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=10))

# Convert string into Unicode
unicode_string = random_string.encode('utf-8')

# Create a temporary file and write the Unicode string to it
temp_file = tempfile.NamedTemporaryFile(delete=False)
temp_file.write(unicode_string)
temp_file.close()

# Output the path of the temporary file
print(temp_file.name)