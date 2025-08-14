## Introduction
Dataset for evaluating LLMs generated code.

## Getting Started
To get started with the project, follow these steps:

1. Clone the repository: `git clone https://github.com/mohkharma/code-llm-evaluation-dataset.git`
2. Review the prompt description files existing in the repository [directory](dataset/).
3. Review the prompt description schema to understand the dataset instance attributes [directory](dataset/promptDescriptionSchema.json).
2. Install dependencies:
3. Run the project: 

## Usage
Here's a brief guide on how to use the project:

##Start generation of responses from the AI models using [main.py](python%2Fmain.py)
##Check for generation completeness using [dir_with_file_count.py](python%2Fdir_with_file_count.py) and [extract-missing-files.py](python%2Fextract-missing-files.py)
##Reprocess the missing using [reprocess_ai_response.py](python%2Freprocess_ai_response.py)
##Fix java class name using [fix_public_class_name_for_java.py](python%2Ffix_public_class_name_for_java.py)


## Generated Code and Unit Tests repositories:

- [C Language Generated Code and Unit Tests](https://github.com/mohsystem/llm_generated_code_c)
- [Python Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-python)
- [C/C++ Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-c-cpp)
- [Java Generated Code and Unit Tests](https://github.com/mohsystem/llm-generated-code-java)


##SonarQube

`D:\Program\sonar-scanner-6.1.0.4477-windows-x64\bin\sonar-scanner.bat -D"sonar.projectKey=code" -D"sonar.so
urces=." -D"sonar.host.url=http://localhost:9000" -D"sonar.token=sqp_63b20fb5ec12ee892ff5cddef124162a9e57bd93"`

https://docs.sonarsource.com/sonarqube/latest/analyzing-source-code/languages/c-family/running-the-analysis/
https://docs.sonarsource.com/sonarqube/10.6/analyzing-source-code/scanners/sonarscanner/

#fix elasticsearch issue
https://stackoverflow.com/questions/42111566/elasticsearch-in-windows-docker-image-vm-max-map-count



## DS semantic evaluation

https://docs.google.com/spreadsheets/d/1eDbnJScw-nh3bsQY7bPI866ivga90wqKy9jnfTI4e3Y/edit?usp=sharing
