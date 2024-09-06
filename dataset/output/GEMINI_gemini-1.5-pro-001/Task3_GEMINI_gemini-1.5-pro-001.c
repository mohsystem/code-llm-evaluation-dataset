#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPangram(char *str) {
  bool seen[26] = {false};
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i])) {
      seen[tolower(str[i]) - 'a'] = true;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!seen[i]) {
      return false;
    }
  }
  return true;
}