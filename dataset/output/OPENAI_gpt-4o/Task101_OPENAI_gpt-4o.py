import os

filename = "script.sh"
with open(filename, 'w') as file:
    file.write("#!/bin/bash\n\necho 'Hello, World!'")
os.chmod(filename, 0o755)