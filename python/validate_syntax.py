import os
import subprocess
import csv

# Define the root directory containing all sources
root_directory = "path/to/your/root_directory"  # Update this path
sources = ["source1", "source2", "source3", "source4"]  # Add your source directories here

# Define file extensions and their corresponding syntax check commands
extensions = {
    "c": "gcc -fsyntax-only",
    "cpp": "g++ -fsyntax-only",
    "java": "javac -d /dev/null",
    "py": "python -m py_compile"
}

# Function to check the syntax of a file
def check_syntax(file_path, command):
    result = "unknown"
    try:
        subprocess.run(f"{command} {file_path}", shell=True, check=True, stderr=subprocess.PIPE)
        result = "valid"
    except subprocess.CalledProcessError:
        result = "not_valid"
    return result

# Dictionary to store the results keyed by task number
results = {}

# Iterate through each source directory
for source in sources:
    source_directory = os.path.join(root_directory, source)
    for root, _, files in os.walk(source_directory):
        for file in files:
            file_extension = file.split(".")[-1]
            if file_extension in extensions:
                file_path = os.path.join(root, file)
                command = extensions[file_extension]
                task_number = os.path.splitext(file)[0]  # Get the file name without extension
                if task_number not in results:
                    results[task_number] = {
                        "validation_for_java": "N/A",
                        "validation_for_c": "N/A",
                        "validation_for_cpp": "N/A",
                        "validation_for_python": "N/A"
                    }
                validation_result = check_syntax(file_path, command)
                if file_extension == "java":
                    results[task_number]["validation_for_java"] = validation_result
                elif file_extension == "c":
                    results[task_number]["validation_for_c"] = validation_result
                elif file_extension == "cpp":
                    results[task_number]["validation_for_cpp"] = validation_result
                elif file_extension == "py":
                    results[task_number]["validation_for_python"] = validation_result

# Write the results to a CSV file
with open("syntax_check_results.csv", "w", newline='') as csvfile:
    fieldnames = ["task_number", "validation_for_java", "validation_for_c", "validation_for_cpp", "validation_for_python"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    for task_number, validation_results in results.items():
        row = {"task_number": task_number}
        row.update(validation_results)
        writer.writerow(row)

print("Syntax check completed. Results saved to syntax_check_results.csv")
