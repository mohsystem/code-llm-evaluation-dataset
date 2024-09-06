import tempfile
import os
import uuid

def create_temp_file_with_unicode():
  """Creates a temporary file with Unicode content.

  Returns:
    str: The path to the created temporary file.
  """
  try:
    # Create a temporary file
    temp_file = tempfile.NamedTemporaryFile(mode='w+', encoding='utf-8', delete=False)
    
    # Generate a random string
    random_string = str(uuid.uuid4())
    
    # Convert the string to Unicode
    unicode_string = random_string

    # Write the Unicode string to the file
    temp_file.write(unicode_string)
    temp_file.close()

    return temp_file.name
  except Exception as e:
    print(f"An error occurred: {e}")
    return None

# Example usage:
temp_file_path = create_temp_file_with_unicode()
if temp_file_path:
  print(f"Temporary file created at: {temp_file_path}")