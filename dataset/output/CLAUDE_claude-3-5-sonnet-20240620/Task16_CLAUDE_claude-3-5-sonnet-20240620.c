
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool solution(const char* str, const char* ending) {
    int str_len = strlen(str);
    int ending_len = strlen(ending);
    
    if (ending_len > str_len) {
        return false;
    }
    
    return strcmp(str + str_len - ending_len, ending) == 0;
}

int main() {
    printf("%s\
", solution("abc", "bc") ? "true" : "false"); // true
    printf("%s\
", solution("abc", "d") ? "true" : "false"); // false
    return 0;
}
