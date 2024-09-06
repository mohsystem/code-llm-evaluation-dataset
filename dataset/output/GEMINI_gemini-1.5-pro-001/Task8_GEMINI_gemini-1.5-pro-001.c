#include <stdio.h>

char findMissingLetter(char *chars, int len) {
  for (int i = 0; i < len - 1; i++) {
    if (chars[i + 1] - chars[i] != 1) {
      return (char)(chars[i] + 1);
    }
  }
  return ' ';
}