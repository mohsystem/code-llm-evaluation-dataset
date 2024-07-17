import subprocess

def get_command_from_user():
    return input("Enter a bash command: ")

def print_output(process):
    for line in iter(process.stdout.readline, b''):
        print(line.decode().strip())
    for line in iter(process.stderr.readline, b''):
        print(line.decode().strip())

def main():
    cmd = get_command_from_user()
    process = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print_output(process)

if __name__ == "__main__":
    main()