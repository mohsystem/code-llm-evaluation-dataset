# Python does not have built-in support for creating executable files.
# However, you can create a shell script and use os.system() to make it executable.

with open('script.sh', 'w') as f:
    f.write('#!/bin/bash\necho "Hello, World!"')

import os
os.system('chmod +x script.sh')