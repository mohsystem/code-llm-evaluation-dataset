#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_token(size_t length) {
  const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  char* token = malloc((length + 1) * sizeof(char));
  if (token == NULL) {
    return NULL;
  }

  srand(time(NULL));
  for (size_t i = 0; i < length; ++i) {
    token[i] = characters[rand() % (sizeof(characters) - 1)];
  }
  token[length] = '\0';

  return token;
}

int main() {
  char* token = generate_token(32);
  if (token != NULL) {
    printf("%s\n", token);
    free(token);
  } else {
    fprintf(stderr, "Memory allocation failed.\n");
    return 1;
  }
  return 0;
}