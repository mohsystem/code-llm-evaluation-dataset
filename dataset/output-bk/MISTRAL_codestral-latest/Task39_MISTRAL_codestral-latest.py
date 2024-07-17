import subprocess

filename = input("Enter the filename: ")
command = "cat " + filename
subprocess.run(command, shell=True)