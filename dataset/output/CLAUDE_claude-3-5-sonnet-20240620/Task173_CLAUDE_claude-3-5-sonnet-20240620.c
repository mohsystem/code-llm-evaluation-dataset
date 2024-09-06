
// C implementation is complex due to lack of built-in string and hash set support.
// Here's a simplified version without Rabin-Karp for demonstration:\n\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#define MAX_LEN 30000\n\nchar* longestDupSubstring(char* s) {\n    int len = strlen(s);\n    char* result = "";\n    int maxLen = 0;\n\n    for (int i = 0; i < len; i++) {\n        for (int j = i + 1; j < len; j++) {\n            int k = 0;\n            while (j + k < len && s[i + k] == s[j + k]) {\n                k++;\n            }\n            if (k > maxLen) {\n                maxLen = k;\n                result = (char*)malloc((maxLen + 1) * sizeof(char));\n                strncpy(result, s + i, maxLen);\n                result[maxLen] = '\\0';
            }
        }
    }

    return result;
}

int main() {
    char s[MAX_LEN];
    scanf("%s", s);
    char* result = longestDupSubstring(s);
    printf("%s\\n", result);
    free(result);
    return 0;
}
