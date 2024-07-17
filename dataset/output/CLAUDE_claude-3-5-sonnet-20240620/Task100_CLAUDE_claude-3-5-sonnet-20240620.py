
import sys
import re

def search_file(regex_pattern, file_name):
    try:
        pattern = re.compile(regex_pattern)
        with open(file_name, \'r\') as file:
            for line_number, line in enumerate(file, 1):
                for match in pattern.finditer(line):
                    print(f"Line {line_number}: {match.group()}")
    except re.error as e:
        print(f"Invalid regular expression: {e}")
    except IOError as e:
        print(f"Error reading file: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: python {sys.argv[0]} <regex_pattern> <file_name>")
        sys.exit(1)

    regex_pattern = sys.argv[1]
    file_name = sys.argv[2]
    search_file(regex_pattern, file_name)
