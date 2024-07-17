import os
import shutil

source_path = 'source.txt'
destination_path = '/tmp/destination.txt'

try:
    with open(source_path, 'r') as file:
        content = file.read()
    
    with open(destination_path, 'w') as file:
        file.write(content)
        
    print("File copied successfully in Python!")

except FileNotFoundError:
    print("The source file does not exist.")
except IOError:
    print("An error occurred while handling the file.")