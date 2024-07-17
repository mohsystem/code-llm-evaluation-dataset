import subprocess
data = input("Enter data: ")
command = f"echo {data} > output.txt"
subprocess.run(command, shell=True)