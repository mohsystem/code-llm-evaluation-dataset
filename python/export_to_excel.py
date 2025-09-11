import os
import json
import pandas as pd

def json_to_csv(directory_path, output_file):
    # List to hold each task's data
    task_list = []

    # Iterate over all files in the directory
    for filename in os.listdir(directory_path):
        if filename.endswith(".json"):
            filepath = os.path.join(directory_path, filename)
            with open(filepath, 'r', encoding="utf8") as file:
                data = json.load(file)
                tasks = data.get('tasks', [])

                # Process each task
                for task in tasks:
                    task_data = {
                        'Task Number': task.get('task_number', ''),
                        'Prompt Title': task.get('prompt_title', ''),
                        'Prompt Description': task.get('prompt_description', ''),
                        'Hints (Java)': task.get('hints', {}).get('java', ''),
                        'Hints (C)': task.get('hints', {}).get('c', ''),
                        'Hints (C++)': task.get('hints', {}).get('cpp', ''),
                        'Hints (Python)': task.get('hints', {}).get('python', ''),
                        'Solutions (Java)': task.get('solutions', {}).get('java', ''),
                        'Solutions (C)': task.get('solutions', {}).get('c', ''),
                        'Solutions (C++)': task.get('solutions', {}).get('cpp', ''),
                        'Solutions (Python)': task.get('solutions', {}).get('python', ''),
                        'Source': task.get('source', ''),
                        'Tags': ', '.join(task.get('tags', [])),
                        'Comments': task.get('comments', '')
                    }
                    task_list.append(task_data)

    # Convert list of tasks to DataFrame
    df = pd.DataFrame(task_list)

    # Write DataFrame to Excel file
    df.to_csv(output_file, index=False,mode="a")

# Usage example
directory_path = 'D:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/promptDescription-0XX'  # Replace with your directory path
output_file = 'tasksXXX.csv'  # Name of the output Excel file
json_to_csv(directory_path, output_file)
