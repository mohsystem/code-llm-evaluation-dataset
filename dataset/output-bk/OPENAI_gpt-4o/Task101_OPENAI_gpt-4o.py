import os

with open('script.sh', 'w') as file:
    file.write('#!/bin/bash
')
    file.write('echo Hello, World!')

os.chmod('script.sh', 0o755)

print('script.sh created and made executable.')