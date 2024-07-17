#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *to_jaden_case (char *jaden_case, const char *string) {
    int i, j = 0, word_start = 1; 
    if (string == NULL) return NULL;

    for (i = 0; string[i] != '\0'; i++) { 
        if (isspace(string[i])) {
            jaden_case[j++] = string[i];
            word_start = 1; 
        }
        else {
            if (word_start) {
              jaden_case[j++] = toupper(string[i]);
              word_start = 0;
            }
            else
              jaden_case[j++] = tolower(string[i]);
        }
    }
    jaden_case[j] = '\0';
  
    return jaden_case; 
}