import os

try:
    with open("script.sh", "w"):
        print("File created: script.sh")
    os.chmod("script.sh", 0o700)
    print("File is now executable")
except Exception as e:
    print("An error occurred:", str(e))