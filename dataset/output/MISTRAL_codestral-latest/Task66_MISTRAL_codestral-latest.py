import subprocess

def validate_command(command):
    # Simple validation: check if command is not empty
    return bool(command.strip())

def execute_command(command):
    if validate_command(command):
        try:
            result = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT, text=True)
            return result
        except subprocess.CalledProcessError as e:
            return f"Error: {e.output}"
    else:
        return "Invalid command"

command = input("Enter a bash shell command: ")
print(execute_command(command))