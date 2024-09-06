#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool solution(const char *str, const char *ending) {
    int str_len = strlen(str);
    int ending_len = strlen(ending);

    if (str_len >= ending_len) {
        return (0 == strcmp(str + str_len - ending_len, ending));
    } else {
        return false;
    }
}

int main() {
    printf("%d\n", solution("abc", "bc"));  // returns true
    printf("%d\n", solution("abc", "d"));   // returns false
    return 0;
}