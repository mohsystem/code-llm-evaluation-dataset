#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generateRandomString(int length) {
  char *str = malloc(sizeof(char) * (length + 1));
  if (str == NULL) {
    return NULL;
  }

  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    str[i] = (rand() % 26) + ((rand() % 2) ? 'a' : 'A');
  }
  str[length] = '\0';

  return str;
}