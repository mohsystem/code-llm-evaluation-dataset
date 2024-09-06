
import subprocess
import shlex
import re

def validate_command(cmd):
    # Basic validation: no empty command, no dangerous commands
    if not cmd.strip() or re.search(r'(rm|sudo|mv|cp|chmod|chown)', cmd):
        return False
    return True

def execute_command(cmd):
    try:
        result = subprocess.run(shlex.split(cmd), capture_output=True, text=True, timeout=10)
        return result.stdout if result.returncode == 0 else result.stderr
    except subprocess.TimeoutExpired:
        return "Command execution timed out"
    except Exception as e:
        return f"Error executing command: {str(e)}"

if __name__ == "__main__":
    while True:
        user_input = input("Enter a bash command (or 'exit' to quit): ")
        if user_input.lower() == 'exit':
            break
        if validate_command(user_input):
            output = execute_command(user_input)
            print("Output:", output)
        else:
            print("Invalid or potentially dangerous command. Please try again.")
