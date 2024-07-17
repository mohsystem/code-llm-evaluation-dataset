import subprocess
import re

def is_valid_command(command):
  """
  Check if the command is valid.
  For simplicity, we only allow alphanumeric characters, spaces, and a few special characters.
  """
  return bool(re.match(r'^[a-zA-Z0-9\s._/-]+$', command))

def execute_command(command):
  """Executes the command and returns the output and error."""
  try:
    process = subprocess.Popen(command.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, error = process.communicate()
    return output.decode(), error.decode()
  except FileNotFoundError:
    return None, f"Error: Command not found: {command}"

if __name__ == "__main__":
  command = input("Enter a bash command: ")
  if is_valid_command(command):
    output, error = execute_command(command)
    if output:
      print(output)
    if error:
      print(error)
  else:
    print("Invalid command format. Please use only alphanumeric characters, spaces, and './-_'")