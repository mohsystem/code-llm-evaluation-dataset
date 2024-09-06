import re
import os


class CodeProcessor:
    def __init__(self, logger, completion_content, output_directory, output_filename):
        self.logger = logger
        self.completion_content = completion_content
        self.output_directory = output_directory
        self.output_filename = output_filename

    def replace_newlines(self, code):
        """Replace \n not within quotes with an actual newline character."""
        pattern = re.compile(r'''
            (["'])            # Match a quote (group 1)
            (                 # Start of group 2
                (?:\\\1|.)*?  # Non-greedy match any character including escaped quotes
            )                 # End of group 2
            \1                # Match the same quote (group 1)
            |                 # OR
            (\\n)             # Match \n not within quotes (group 3)
        ''', re.VERBOSE)

        def replace_match(match):
            if match.group(3):
                return '\n'  # Replace \n not in quotes with a newline character
            return match.group(0)  # Keep the quoted part as it is

        return pattern.sub(replace_match, code)

    def process_sections(self):
        # Split the completion_content into sections based on language
        sections = re.split(r'```', self.completion_content)

        # Process each section and create respective output files
        for section in sections:
            if not section.strip():
                continue

            keywords = ["python", "cpp", "java", "Python", "CPP", "Java", "C++", "c++", "c", "C"]
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

                formatted_code = self.replace_newlines(code)
                with open(output_path, 'w', encoding="utf-8") as output_file:
                    output_file.write(formatted_code)

                print(f"Created file: {output_filename}")
                self.logger.info(f"Created file: {output_filename}")


# Example usage:
if __name__ == "__main__":
    import logging

    logging.basicConfig(level=logging.INFO)
    logger = logging.getLogger(__name__)

    completion_content = """
    ```python
    print("Hello, world!\\n")
    def foo():
        return "bar\\n"
    ```

    ```cpp
    #include <iostream>
    int main() {
        std::cout << "Hello, world!\\n";
        return 0;
    }
    ```
    """
    output_directory = "./output"
    output_filename = "output_file"

    processor = CodeProcessor(logger, completion_content, output_directory, output_filename)
    processor.process_sections()
