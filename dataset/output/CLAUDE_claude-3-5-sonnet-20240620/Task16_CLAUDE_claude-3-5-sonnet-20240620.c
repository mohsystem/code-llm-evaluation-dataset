
#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
    int str_len = strlen(string);
    int end_len = strlen(ending);
    
    if (end_len > str_len)
        return false;
    
    return strcmp(string + str_len - end_len, ending) == 0;
}
