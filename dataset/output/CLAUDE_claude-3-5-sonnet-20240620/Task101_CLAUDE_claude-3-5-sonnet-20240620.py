
import os

# Create the file
with open('script.sh', 'w') as file:
    file.write('#!/bin/bash\\necho "Hello, World!"')

# Make it executable
os.chmod('script.sh', 0o755)
