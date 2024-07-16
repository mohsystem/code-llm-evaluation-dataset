import datetime
import os
import json
import shutil
import logging
import time

from claude_integration import ClaudeIntegration
from code_processor import CodeProcessor
from gemini_integration import GeminiIntegration
from mistral_integration import MistralIntegration
from openai_integration import OpenAIIntegration
from perplexity_integration import PerplexityIntegration

# Directory where JSON files are located
input_directory = 'C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/test'

# Selected Model
# selected_model = "gpt-4o"

# output file extension
# programming_language = "java"

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

# Get today's date in YYYY-MM-DD format
today = datetime.date.today().strftime('%Y-%m-%d_%H-%M-%S')

# Configure logging to write to a file with date in filename
logging.basicConfig(filename=f"logs/processing_{active_integration[0] + '_' + active_integration[1]}_{today}.log", level=logging.DEBUG, format="%(asctime)s %(levelname)s %(message)s")

logger = logging.getLogger(__name__)


# Directory where output files will be stored
output_directory = f"C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/{active_integration[0]+'_' + active_integration[1]}"

# Instruction message
instruction_message = ('Instructions: \n'
                       '1) The output should include only the code, do not include any other output or descriptions.\n'
                       '2) Write the code in the following four programming languages: Java, C, C++, Python.\n'
                       '3) Put the code like the below template/example:\n'
                       '```python  \n'
                       'code here:\n'
                       '```\n'
                       '```java  \n'
                       'code here:\n'
                       '```\n'
                       '```cpp  \n'
                       'code here:\n'
                       '```\n'
                       '```c  \n'
                       'code here:\n'
                       '```\n'
                       '4) we need the output program run as one source code file. All code needs to be in one file\n')

# Ensure output directory exists or create it
os.makedirs(output_directory, exist_ok=True)


# Iterate over each file in the input directory
def sorted_directory_listing_with_os_listdir(directory):
    items = os.listdir(directory)
    sorted_items = sorted(items)
    return sorted_items


for filename in sorted_directory_listing_with_os_listdir(input_directory):
    if filename.endswith('.json'):
        file_path = os.path.join(input_directory, filename)

        # Read JSON data from the file
        with open(file_path,  mode='r', encoding="utf8") as file:
            data = json.load(file)

        # Extract the prompt_description from the JSON data
        prompt_description = data['tasks'][0]['prompt_description']
        prompt_description_id = data['tasks'][0]['task_number']
        task_number = data['tasks'][0]['task_number']
        prompt_title = data['tasks'][0]['prompt_title']
        output_filename = "Task" + str(task_number) + '_' + active_integration[0] + '_' + active_integration[1]
        print(output_filename + "_" + instruction_message + prompt_description)
        logger.info(output_filename + "_" + instruction_message + prompt_description)

        # Print the prompt_description
        # print(instruction_message + prompt_description)
        model_response = None
        # Call the AI model integration
        generated_text = None
        if active_integration[0] == gemini_model[0]:
            model_name = gemini_model[1]
            # model_name = 'gemini-1.0-pro-latest'
            # Initialize Gemini Model
            processor = GeminiIntegration(model_name)

            # Generate content using the model
            generated_text = processor.generate_content(instruction_message + prompt_description)
            model_response = generated_text
            logger.info(generated_text)
            print(generated_text)
        elif active_integration[0] == mistral_model[0]:
            model_name = mistral_model[1]
            # Initialize Mistral Model
            processor = MistralIntegration(model_name)

            # Generate content using the model
            generated_text = processor.generate_content(instruction_message + prompt_description)
            model_response = generated_text
            logger.info(generated_text)
            print(generated_text)
        elif active_integration[0] == claude_model[0]:
            model_name = claude_model[1]
            # Initialize CLAUDE Model
            processor = ClaudeIntegration(model_name)

            # Generate content using the model
            generated_text = processor.generate_content(instruction_message, prompt_description)
            model_response = ','.join(map(str, generated_text))
            logger.info(model_response)
            print(model_response)
        elif active_integration[0] == openai_model[0]:
            # Initialize OpenAI GPT Model
            selected_model = openai_model[1]
            openAIIntegration = OpenAIIntegration()
            generated_text = openAIIntegration.get_completion_content(instruction_message + prompt_description, selected_model)
            model_response = generated_text.choices[0].message.content
            print(generated_text.choices[0].message.content)
            logger.info(model_response)
        elif active_integration[0] == perplexity_model[0]:
            # Initialize PERPLEXITY Model
            selected_model = perplexity_model[1]
            perplexityIntegration = PerplexityIntegration()
            generated_text = perplexityIntegration.get_completion_content(instruction_message + prompt_description, selected_model)
            model_response = generated_text.choices[0].message.content
            print(generated_text.choices[0].message.content)
            logger.info(model_response)
        else:
            print(f"Unsupported active integration: {active_integration}")
            logger.info(f"Unsupported active integration: {active_integration}")

        # Write the prompt_description to a new file in the output directory
        # + '.' + programming_language
        # output_path = os.path.join(output_directory, output_filename)

        codeProcessor = CodeProcessor(logger, model_response, output_directory, output_filename)
        codeProcessor.process_sections()
        # Sleep for 2 seconds
        time.sleep(5)


# with open(output_path, 'w') as output_file:
        #     output_file.write(completion_content.choices[0].message.content.replace('```java', '') .replace('```', ''))

        # print(f'Created file: {output_path}')

print('All files processed.')
logger.info('All files processed.')
