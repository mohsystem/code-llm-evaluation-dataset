## Introduction
Dataset for evaluating LLMs generated code, developed for "Security and Quality in LLM-Generated Code: A Multi-Language, Multi-Model Analysis" research paper.

## Getting Started
To get started with the project, follow these steps:

1. Clone the repository: `git clone https://github.com/mohkharma/code-llm-evaluation-dataset.git`
2. Review the prompt description files existing in the repository [directory](dataset/promptDescription-XXX).
3. Review the prompt description schema to understand the dataset instance attributes [directory](dataset/promptDescriptionSchema.json).


## Usage
Here's a brief guide on how to use the project:

##Start generation of responses from the AI models using [main.py](python%2Fmain.py)
##Check for generation completeness using [dir_with_file_count.py](python%2Fdir_with_file_count.py) and [extract-missing-files.py](python%2Fextract-missing-files.py)
##Reprocess the missing using [reprocess_ai_response.py](python%2Freprocess_ai_response.py)
##Fix java class name using [fix_public_class_name_for_java.py](python%2Ffix_public_class_name_for_java.py)


## Generated Code and Unit Tests Repositories:

- [C Language Generated Code and Unit Tests](https://github.com/mohsystem/llm_generated_code_c)
- [Python Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-python)
- [C/C++ Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-c-cpp)
- [Java Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-java)


## SonarQube Scanning

`sonar-scanner.bat -D"sonar.projectKey=<projectKey>" -D"sonar.so
urces=." -D"sonar.host.url=http://localhost:9000" -D"sonar.token=<token>"`

# Download sonar-scanner:
https://docs.sonarsource.com/sonarqube/10.6/analyzing-source-code/scanners/sonarscanner/


# Fix elasticsearch issue
https://stackoverflow.com/questions/42111566/elasticsearch-in-windows-docker-image-vm-max-map-count

# Running the CFamily analysis
https://docs.sonarsource.com/sonarqube-server/latest/analyzing-source-code/languages/c-family/running-the-analysis/

## DS semantic evaluation

https://docs.google.com/spreadsheets/d/1ZgDLF5GZX362IVPcpj9DYC4Ru7816g6du6dLa3hKCXY/edit?usp=sharing
