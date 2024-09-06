
import tempfile
import random
import string

def create_temp_file_with_unicode():
    # Create a temporary file
    temp_file = tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', delete=False)
    
    # Generate a random string
    random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=10))
    
    # Convert the string to Unicode
    unicode_string = random_string.encode('unicode_escape').decode('utf-8')
    
    # Write the Unicode string to the file
    temp_file.write(unicode_string)
    temp_file.close()
    
    return temp_file.name

# Call the function and print the path
print(create_temp_file_with_unicode())
