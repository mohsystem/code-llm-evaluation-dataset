
import subprocess
import re

def validate_command(command):
    # Check if command is empty
    if not command:
        return False
    
    # Check for semicolons, pipes, or redirections
    if re.search(r\'[;|><]\', command):
        return False
    
    return True

def main():
    command = input("Enter a bash command: ")

    if validate_command(command):
        try:
            result = subprocess.run([\'bash\', \'-c\', command], capture_output=True, text=True, check=True)
            print(result.stdout)
        except subprocess.CalledProcessError as e:
            print(f"Command execution failed: {e}")
            print(f"Error output: {e.stderr}")
    else:
        print("Invalid command format or content.")

if __name__ == "__main__":
    main()
