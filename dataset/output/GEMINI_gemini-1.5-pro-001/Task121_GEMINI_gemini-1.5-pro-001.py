import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox

root = tk.Tk()
root.withdraw()

file_path = filedialog.askopenfilename()

if file_path:
    try:
        with open(file_path, 'rb') as file:
            # Process the uploaded file here
            file_content = file.read()
            # ...
        messagebox.showinfo("Success", "File uploaded successfully!")
    except FileNotFoundError:
        messagebox.showerror("Error", f"File not found: {file_path}")
else:
    messagebox.showinfo("Info", "No file selected.")