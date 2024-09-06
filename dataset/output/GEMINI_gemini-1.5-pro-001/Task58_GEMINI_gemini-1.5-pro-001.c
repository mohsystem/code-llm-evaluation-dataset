#include <string.h>
#include <ctype.h>

bool XO(const char* text) {
  int x_count = 0;
  int o_count = 0;
  for (int i = 0; text[i] != '\0'; i++) {
    char c = tolower(text[i]);
    if (c == 'x') {
      x_count++;
    } else if (c == 'o') {
      o_count++;
    }
  }
  return x_count == o_count;
}