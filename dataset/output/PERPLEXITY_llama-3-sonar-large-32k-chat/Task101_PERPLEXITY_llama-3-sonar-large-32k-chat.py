import os
with open("script.sh", "w") as f:
    f.write("#!/bin/bash\necho 'Hello World!'")
os.chmod("script.sh", 0o755)