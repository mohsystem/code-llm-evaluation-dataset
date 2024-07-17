#include <stdbool.h>
#include <string.h>

bool isValid(char *walk, int length) {
  if (length != 10) {
    return false;
  }
  int x = 0;
  int y = 0;
  for (int i = 0; i < length; i++) {
    char c = walk[i];
    if (c == 'n') {
      y++;
    } else if (c == 's') {
      y--;
    } else if (c == 'e') {
      x++;
    } else if (c == 'w') {
      x--;
    }
  }
  return x == 0 && y == 0;
}