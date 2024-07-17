import re
import os


class CodeProcessor:
    def __init__(self, logger, completion_content, output_directory, output_filename):
        self.logger = logger
        self.completion_content = completion_content
        self.output_directory = output_directory
        self.output_filename = output_filename

    def process_sections(self, ):
        # Split the completion_content into sections based on language
        sections = re.split(r'```', self.completion_content)

        # Process each section and create respective output files
        for section in sections:
            if not section.strip():
                continue

            keywords = ["python", "cpp", "java",  "Python", "CPP", "Java", "C++", "c++", "c", "C",]
            language = None

            # Check if text starts with any keyword from the list
            for keyword in keywords:
                if section.startswith(keyword):
                    # Remove the keyword from the beginning of the text
                    section = section[len(keyword):].lstrip()
                    language = (keyword.replace('python', 'py')
                                .replace('Python', 'py')
                                .replace('Java', 'java')
                                .replace('CPP', 'cpp')
                                .replace('c++', 'cpp')
                                .replace('C++', 'cpp')
                                .replace('C', 'c')
                                )
                    break
            if language is not None:
                code = section.strip()  # Remove leading/trailing whitespace

                file_name = self.output_filename
                # Define output filename
                output_filename = f"{file_name}.{language}"
                output_path = os.path.join(self.output_directory, output_filename)

                with open(output_path, 'w', encoding="utf-8") as output_file:
                    output_file.write(code.replace(r'\n', '\n'))

                print(f"Created file: {file_name}")
                self.logger.info(f"Created file: {file_name}")
