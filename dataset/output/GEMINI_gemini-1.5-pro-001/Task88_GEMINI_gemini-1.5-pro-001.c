#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

char *generate_random_string(int length) {
  char *string = malloc(length + 1);
  const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const int characters_length = sizeof(characters) - 1;

  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    string[i] = characters[rand() % characters_length];
  }
  string[length] = '\0';

  return string;
}

char *convert_to_unicode(const char *string) {
  size_t string_length = strlen(string);
  char *unicode_string = malloc((string_length * 6) + 1);
  char *ptr = unicode_string;

  for (size_t i = 0; i < string_length; i++) {
    ptr += sprintf(ptr, "\\u%04X", string[i]);
  }

  return unicode_string;
}

int main() {
  char temp_filename[] = "tempXXXXXX";
  int file_descriptor = mkstemp(temp_filename);
  if (file_descriptor == -1) {
    perror("Failed to create temporary file");
    return 1;
  }

  char *random_string = generate_random_string(10);
  char *unicode_string = convert_to_unicode(random_string);

  FILE *temp_file = fdopen(file_descriptor, "w");
  if (!temp_file) {
    perror("Failed to open temporary file");
    return 1;
  }

  fprintf(temp_file, "%s", unicode_string);
  fclose(temp_file);

  printf("%s
", temp_filename);

  free(random_string);
  free(unicode_string);

  return 0;
}