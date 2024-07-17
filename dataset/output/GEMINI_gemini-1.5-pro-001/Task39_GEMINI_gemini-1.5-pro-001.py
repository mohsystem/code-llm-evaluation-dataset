import os

filename = input("Enter the filename: ")
try:
    with open(filename, 'r') as f:
        print(f.read())
except FileNotFoundError:
    print(f"Error: File '{filename}' not found.")