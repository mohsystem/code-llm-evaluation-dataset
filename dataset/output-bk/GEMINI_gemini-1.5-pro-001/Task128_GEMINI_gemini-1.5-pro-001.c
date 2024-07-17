#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
  srand(time(NULL));
  return rand() % (max - min + 1) + min;
}

char* generateRandomToken(int length) {
  const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  char *token = malloc(length + 1);
  if (token == NULL) {
    return NULL;
  }

  srand(time(NULL));
  for (int i = 0; i < length; ++i) {
    token[i] = characters[rand() % (sizeof(characters) - 1)];
  }
  token[length] = '\0';
  return token;
}

int main() {
  int randomNumber = generateRandomNumber(1, 10);
  printf("Random number between 1 and 10: %d
", randomNumber);

  char *randomToken = generateRandomToken(20);
  if (randomToken != NULL) {
    printf("Random token of length 20: %s
", randomToken);
    free(randomToken);
  }

  return 0;
}