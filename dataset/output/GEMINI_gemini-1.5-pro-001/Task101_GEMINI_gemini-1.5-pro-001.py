#!/usr/bin/env python3
import os
# Create the file
open('script.sh', 'w').close()
# Make it executable
os.chmod('script.sh', 0o755)