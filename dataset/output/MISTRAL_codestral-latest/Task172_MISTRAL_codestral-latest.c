#include <string.h>
#include <stdbool.h>
bool repeatedSubstringPattern(char * s) {
    int len = strlen(s);
    for (int i = 1; i * 2 <= len; ++i) {
        if (len % i == 0) {
            bool match = true;
            for (int j = i; j < len; ++j) {
                if (s[j] != s[j - i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    return false;
}