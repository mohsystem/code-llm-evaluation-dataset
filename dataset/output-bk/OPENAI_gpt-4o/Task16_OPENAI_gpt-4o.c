#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool solution(const char *str, const char *ending) {
    size_t str_len = strlen(str);
    size_t ending_len = strlen(ending);
    
    if (ending_len > str_len) {
        return false;
    }
    
    return strcmp(str + str_len - ending_len, ending) == 0;
}

int main() {
    printf("%d
", solution("abc", "bc")); // 1
    printf("%d
", solution("abc", "d")); // 0
    return 0;
}