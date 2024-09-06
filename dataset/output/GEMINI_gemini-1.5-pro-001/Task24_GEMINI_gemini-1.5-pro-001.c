#include <stdbool.h>
#include <string.h>
#include <regex.h> 

bool validate_pin(const char* pin) {
  regex_t regex;
  int reti;
  
  reti = regcomp(&regex, "^(?:[0-9]{4}|[0-9]{6})$", REG_EXTENDED);
  if (reti) {
    return false;
  }
  
  reti = regexec(&regex, pin, 0, NULL, 0);
  regfree(&regex);
  
  return reti == 0;
}