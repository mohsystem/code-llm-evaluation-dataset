import os
import re

# This program is to change the name of the public class in java files to be same as the file name with replacing
# the non-alphanumeric characters with underscore to avoid compilation errors.

# Function to clean the class name
def clean_class_name(file_name):
    # Remove the file extension
    base_name = os.path.splitext(file_name)[0]
    # Remove non-alphanumeric characters and capitalize
    clean_name = re.sub(r'[^0-9a-zA-Z]', '_', base_name)
    return clean_name


# Function to update the class name in the Java file
def update_class_name_in_file(file_path, new_class_name):
    with open(file_path, 'r') as file:
        content = file.read()

    # Find the current public class name
    class_name_pattern = re.compile(r'public\s+class\s+(\w+)')
    match = class_name_pattern.search(content)

    if match:
        old_class_name = match.group(1)
        # Replace old class name with new class name
        updated_content = content.replace(f'public class {old_class_name}', f'public class {new_class_name}')
        updated_content = updated_content.replace(f'public {old_class_name}', f'public {new_class_name}')
        updated_content = updated_content.replace(f' {old_class_name} ', f' {new_class_name} ')
        updated_content = updated_content.replace(f' {old_class_name}(', f' {new_class_name}(')
        updated_content = updated_content.replace(f' {old_class_name}.', f' {new_class_name}.')
        updated_content = updated_content.replace(f'({old_class_name}.', f'({new_class_name}.')
        updated_content = updated_content.replace(f'({old_class_name})', f'({new_class_name})')

        with open(file_path, 'w') as file:
            file.write(updated_content)

        return old_class_name, new_class_name

    return None, None

# Function to rename the file
def rename_file(directory, old_file_name, new_file_name):
    old_file_path = os.path.join(directory, old_file_name)
    new_file_path = os.path.join(directory, f"{new_file_name}.java")
    os.rename(old_file_path, new_file_path)
    return new_file_path

# Directory containing the Java files
# directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/CLAUDE_claude-3-5-sonnet-20240620"  # Update this path
# directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/test"  # Update this path
# directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/GEMINI_gemini-1.5-pro-001"  # Update this path
# directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/MISTRAL_codestral-latest"  # Update this path
# directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/OPENAI_gpt-4o"  # Update this path
directory = "C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/PERPLEXITY_llama-3-sonar-large-32k-chat"  # Update this path

# Process each Java file in the directory
for file_name in os.listdir(directory):
    if file_name.endswith('.java'):
        file_path = os.path.join(directory, file_name)
        print(file_name)
        # Generate the new class name
        new_class_name = clean_class_name(file_name)

        # Update the class name inside the file
        old_class_name, updated_class_name = update_class_name_in_file(file_path, new_class_name)

        if old_class_name and updated_class_name:
            # Rename the Java file
            new_file_name = f"{updated_class_name}.java"
            new_file_path = rename_file(directory, file_name, updated_class_name)
            print(f"Renamed class '{old_class_name}' to '{updated_class_name}' and file '{file_name}' to '{new_file_name}'")
            # if updated_class_name is None,
        else:
            new_file_name = file_name
        # move file to subdirectory and name the subdirectory with the same updated_class_name

        new_directory = os.path.join(directory, file_name.split("_")[0].lower())
        os.makedirs(new_directory, exist_ok=True)
        os.rename(os.path.join(directory, new_file_name), os.path.join(new_directory, new_file_name))
