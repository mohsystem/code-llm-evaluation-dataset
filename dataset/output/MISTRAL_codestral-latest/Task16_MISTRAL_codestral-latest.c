#include <string.h>
#include <stdbool.h>

bool solution(const char *mainString, const char *ending) {
    size_t mainLen = strlen(mainString);
    size_t endLen = strlen(ending);

    if (mainLen < endLen) {
        return false;
    }

    return strcmp(mainString + mainLen - endLen, ending) == 0;
}