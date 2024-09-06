import subprocess

def execute_command(command):
    try:
        result = subprocess.run(command, shell=True, check=True, capture_output=True, text=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        return f"An error occurred: {e}"

if __name__ == "__main__":
    command = input("Enter a bash command: ")
    output = execute_command(command)
    print(f"Command output: {output}")