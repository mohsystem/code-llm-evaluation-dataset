import os
from collections import defaultdict

import os
import shutil
import os
import re
# This program is to extract the failed to generated prompts
# openAIIntegration = OpenAIIntegration()
openai_model = ["OPENAI", "gpt-4o"]  # https://platform.openai.com/docs/models
gemini_model = ["GEMINI", "gemini-1.5-pro-001"] # https://console.cloud.google.com/vertex-ai/generative/language/create/text?createType=code&project=gen-lang-client-0375481745
perplexity_model = ["PERPLEXITY", "llama-3-sonar-large-32k-chat"] # https://docs.perplexity.ai/docs/model-cards
claude_model = ["CLAUDE", "claude-3-5-sonnet-20240620"] # https://docs.anthropic.com/en/docs/about-claude/models
mistral_model = ["MISTRAL", "codestral-latest"]    # https://mistral.ai/technology/ # https://docs.mistral.ai/api/#operation/createFIMCompletion

# Set the active integration
# active_integration = openai_model
active_integration = gemini_model
# active_integration = perplexity_model
# active_integration = claude_model
# active_integration = mistral_model


# Function to extract task numbers from filenames
def extract_task_numbers(directory):
    task_numbers = []
    pattern = re.compile(r'Task(\d+)_')

    for file_name in os.listdir(directory):
        match = pattern.search(file_name)
        if match:
            task_number = int(match.group(1))
            task_numbers.append(task_number)

    return sorted(task_numbers)

# Function to find missing numbers in a sequence
def find_missing_numbers(task_numbers):
    if not task_numbers:
        return []

    full_range = set(range(task_numbers[0], task_numbers[-1] + 1))
    missing_numbers = sorted(full_range - set(task_numbers))

    return missing_numbers

# Directory containing the files
directory = f"C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/{active_integration[0] + '_' + active_integration[1]}"

# Extract task numbers from filenames
task_numbers = extract_task_numbers(directory)
# print(f"Task Numbers: {task_numbers}")

# Find missing task numbers
missing_numbers = find_missing_numbers(task_numbers)
print(f"Missing Task Numbers: {missing_numbers}")

for file_name in missing_numbers:
    print(f"{file_name}")
    formatted_task_number = f"{int(file_name):03d}"

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

