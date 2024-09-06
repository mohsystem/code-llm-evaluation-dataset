import os
script_content = '#!/bin/bash\necho "Hello from script.sh!"\n'
with open('script.sh', 'w') as file:
    file.write(script_content)
os.chmod('script.sh', 0o755)