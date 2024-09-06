import subprocess
filename = input("Enter a filename: ")
subprocess.run(["cat", filename])