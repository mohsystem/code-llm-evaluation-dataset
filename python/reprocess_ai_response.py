from code_processor import CodeProcessor
import logging
import time
import datetime

openai_model = ["OPENAI", "gpt-4o"]  # https://platform.openai.com/docs/models
gemini_model = ["GEMINI", "gemini-1.5-pro-001"] # https://console.cloud.google.com/vertex-ai/generative/language/create/text?createType=code&project=gen-lang-client-0375481745
perplexity_model = ["PERPLEXITY", "llama-3-sonar-large-32k-chat"] # https://docs.perplexity.ai/docs/model-cards
claude_model = ["CLAUDE", "claude-3-5-sonnet-20240620"] # https://docs.anthropic.com/en/docs/about-claude/models
mistral_model = ["MISTRAL", "codestral-latest"]    # https://mistral.ai/technology/ # https://docs.mistral.ai/api/#operation/createFIMCompletion

# Set the active integration
# active_integration = openai_model
# active_integration = gemini_model
active_integration = perplexity_model
# active_integration = claude_model
# active_integration = mistral_model


# Get today's date in YYYY-MM-DD format
today = datetime.date.today().strftime('%Y-%m-%d_%H-%M-%S')

# Configure logging to write to a file with date in filename
logging.basicConfig(filename=f"logs/processing.log", level=logging.DEBUG, format="%(asctime)s %(levelname)s %(message)s")

output_directory = f"C:/sourceCode/PhD/code-llm-evaluation-dataset/dataset/output/{active_integration[0]+'_' + active_integration[1]}"

logger = logging.getLogger(__name__)
model_response = """
```Java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        String fileName = "input.txt";
        String regexPattern = "^[0-9].*\\.$";
        
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            Pattern pattern = Pattern.compile(regexPattern);
            
            while ((line = br.readLine()) != null) {
                Matcher matcher = pattern.matcher(line);
                if (matcher.find()) {
                    System.out.println(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

```C
#include <stdio.h>
#include <regex.h>

void match_lines(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    regex_t regex;
    int reti = regcomp(&regex, "^[0-9].*\\.$", REG_EXTENDED);
    if (reti) {
        fclose(file);
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("%s", line);
        }
    }

    regfree(&regex);
    fclose(file);
}

int main() {
    const char *file_name = "input.txt";
    match_lines(file_name);
    return 0;
}
```

```C++
#include <iostream>
#include <fstream>
#include <regex>

void match_lines(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    std::regex pattern(R"(^[0-9].*\.$)");
    std::string line;
    while (std::getline(file, line)) {
        if (std::regex_match(line, pattern)) {
            std::cout << line << std::endl;
        }
    }

    file.close();
}

int main() {
    const std::string file_name = "input.txt";
    match_lines(file_name);
    return 0;
}
```

```Python
import re

def match_lines(file_name):
    pattern = re.compile(r"^[0-9].*\.$")
    
    with open(file_name, 'r') as file:
        for line in file:
            if pattern.match(line):
                print(line, end='')

if __name__ == "__main__":
    file_name = "input.txt"
    match_lines(file_name)
```
"""
task_number = "99"
output_filename = "Task" + str(task_number) + '_' + active_integration[0] + '_' + active_integration[1]

codeProcessor = CodeProcessor(logger, model_response, output_directory, output_filename)
codeProcessor.process_sections()