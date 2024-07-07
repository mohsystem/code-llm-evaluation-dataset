import os
import json
import shutil

from code_processor import CodeProcessor
from gemini_integration import GenerativeAIProcessor
from openai_integration import OpenAIIntegration
from perplexity_integration import PerplexityIntegration

# Directory where JSON files are located
input_directory = 'C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/test'

# Selected Model
# selected_model = "gpt-4o"

# output file extension
# programming_language = "java"

# openAIIntegration = OpenAIIntegration()

# Set the active integration
active_integration = "OPENAI"
# active_integration = "GEMINI"
# active_integration = "PERPLEXITY"

# Directory where output files will be stored
output_directory = f"C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/{active_integration}"

# Instruction message
instruction_message = ('The output should include only the code, dont include any other output or description. '
                       'Write the code in the following four programming languages: Java, C, C++, Python. Put the code '
                       'inside ```<language name>  ``` block.'
                       'Also, we need the output program run as one source code file. All code needs to be in one '
                       'file\n')

# Ensure output directory exists or create it
os.makedirs(output_directory, exist_ok=True)

# Iterate over each file in the input directory
for filename in os.listdir(input_directory):
    if filename.endswith('.json'):
        file_path = os.path.join(input_directory, filename)

        # Read JSON data from the file
        with open(file_path, 'r') as file:
            data = json.load(file)

        # Extract the prompt_description from the JSON data
        prompt_description = data['tasks'][0]['prompt_description']
        prompt_description_id = data['tasks'][0]['task_number']
        task_number = data['tasks'][0]['task_number']
        prompt_title = data['tasks'][0]['prompt_title']

        # Print the prompt_description
        print(instruction_message + prompt_description)
        model_response = None
        # Call the AI model integration
        generated_text = None
        if active_integration == "GEMINI":
            model_name = 'gemini-1.0-pro-latest'
            # Initialize Gemini Model
            processor = GenerativeAIProcessor(model_name)

            # Generate content using the model
            generated_text = processor.generate_content(instruction_message + prompt_description)
            model_response = generated_text
            print(generated_text)
        elif active_integration == "OPENAI":
            # Initialize OpenAI GPT Model
            selected_model = "gpt-4o"
            openAIIntegration = OpenAIIntegration()
            generated_text = openAIIntegration.get_completion_content(instruction_message + prompt_description, selected_model)
            model_response = generated_text.choices[0].message.content
            print(generated_text.choices[0].message.content)
        elif active_integration == "PERPLEXITY":
            # Initialize PERPLEXITY Model
            # https://docs.perplexity.ai/docs/model-cards
            # https://deepmind.google/technologies/gemini/pro/
            # https://www.perplexity.ai/settings/api
            selected_model = "llama-3-sonar-large-32k-chat"
            perplexityIntegration = PerplexityIntegration()
            generated_text = perplexityIntegration.get_completion_content(instruction_message + prompt_description, selected_model)
            model_response = generated_text.choices[0].message.content
            print(generated_text.choices[0].message.content)
        else:
            print(f"Unsupported active integration: {active_integration}")

        # Write the prompt_description to a new file in the output directory
        # + '.' + programming_language
        output_filename = "Task" + str(task_number) + '_' + active_integration
        # output_path = os.path.join(output_directory, output_filename)

        codeProcessor = CodeProcessor(model_response, output_directory, output_filename)
        codeProcessor.process_sections()

        # with open(output_path, 'w') as output_file:
        #     output_file.write(completion_content.choices[0].message.content.replace('```java', '') .replace('```', ''))

        # print(f'Created file: {output_path}')

print('All files processed.')
