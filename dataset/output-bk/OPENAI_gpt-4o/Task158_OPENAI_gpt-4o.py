import subprocess

def run_command():
    command = input("Enter a command to run: ")
    subprocess.run(command, shell=True)

if __name__ == "__main__":
    run_command()