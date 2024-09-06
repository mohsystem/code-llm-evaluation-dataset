#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_session_id(size_t length) {
  const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  char *session_id = malloc(length + 1);
  if (session_id == NULL) {
    return NULL;
  }

  srand(time(NULL));
  for (size_t i = 0; i < length; ++i) {
    session_id[i] = characters[rand() % (sizeof(characters) - 1)];
  }
  session_id[length] = '\0';

  return session_id;
}