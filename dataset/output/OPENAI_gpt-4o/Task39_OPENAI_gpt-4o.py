import os

filename = input("Enter the filename: ")
os.system(f"type {filename}") if os.name == 'nt' else os.system(f"cat {filename}")