import os

with open("script.sh", "w") as file:
    file.write("#!/bin/bash
echo 'Hello World'
")
os.system("chmod +x script.sh")