import os
from collections import defaultdict

import os
import shutil

# This program is to know prompts that have not generated languages in the 4 programming languages
# openAIIntegration = OpenAIIntegration()
openai_model = ["OPENAI", "gpt-4o"]  # https://platform.openai.com/docs/models
gemini_model = ["GEMINI", "gemini-1.5-pro-001"] # https://console.cloud.google.com/vertex-ai/generative/language/create/text?createType=code&project=gen-lang-client-0375481745
perplexity_model = ["PERPLEXITY", "llama-3-sonar-large-32k-chat"] # https://docs.perplexity.ai/docs/model-cards
claude_model = ["CLAUDE", "claude-3-5-sonnet-20240620"] # https://docs.anthropic.com/en/docs/about-claude/models
mistral_model = ["MISTRAL", "codestral-latest"]    # https://mistral.ai/technology/ # https://docs.mistral.ai/api/#operation/createFIMCompletion

# Set the active integration
# active_integration = openai_model
# active_integration = gemini_model
# active_integration = perplexity_model
# active_integration = claude_model
active_integration = mistral_model

# Define the directory to search for files
directory = f"C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/{active_integration[0] + '_' + active_integration[1]}"

# Create a dictionary to store the file name (without extension) and its count
file_counts = defaultdict(int)

# Walk through the directory and its subdirectories
for root, _, files in os.walk(directory):
    for file in files:
        # Get the file name without extension
        file_name_without_extension = os.path.splitext(file)[0]
        # Increment the count for the file name
        file_counts[file_name_without_extension] += 1

# Function to extract and format the task number
def format_task_number(task_string):
    # Extract the number after "Task"
    task_number = ''.join(filter(str.isdigit, task_string.split('_')[0]))
    # Format as three-digit number
    formatted_number = f"{int(task_number):03d}"
    return formatted_number

# Display the file name and its count
print(f"{'File Name':<40} Count")
print("-" * 50)
for file_name, count in file_counts.items():
    if count != 4:
        print(f"{file_name:<40} {count}")
        formatted_task_number = format_task_number(file_name)
        # Source and destination directories
        source_directory = 'C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/promptDescription-0XX'  # Update this with the actual path
        destination_directory = 'C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/test'

        # File name to copy
        file_name = f"promptDescription-{formatted_task_number}.json"
        # Construct full file paths
        source_file_path = os.path.join(source_directory, file_name)
        destination_file_path = os.path.join(destination_directory, file_name)

        # Check if the source file exists
        if os.path.exists(source_file_path):
            # Copy the file to the destination directory
            shutil.copy(source_file_path, destination_file_path)
            print(f"File copied to: {destination_file_path}")
        else:
            print(f"Source file does not exist: {source_file_path}")
            source_directory = 'C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/promptDescription-1XX'  # Update this with the actual path
            source_file_path = os.path.join(source_directory, file_name)

            # Copy the file to the destination directory
            shutil.copy(source_file_path, destination_file_path)
            print(f"File copied to: {destination_file_path}")

