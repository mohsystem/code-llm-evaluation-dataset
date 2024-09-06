import os

# Get user input
user_input = input("Enter data for OS command: ")

# Construct the OS command
command = f"your_command_here {user_input}"

# Execute the command
os.system(command)