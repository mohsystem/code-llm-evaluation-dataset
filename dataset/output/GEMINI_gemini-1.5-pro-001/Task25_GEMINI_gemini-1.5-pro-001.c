#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **number(char **lines, int lines_size) {
  char **numbered_lines = malloc(lines_size * sizeof(char *));
  for (int i = 0; i < lines_size; i++) {
    int line_number = i + 1;
    int line_length = strlen(lines[i]);
    int buffer_size = snprintf(NULL, 0, "%d: %s", line_number, lines[i]) + 1;
    numbered_lines[i] = malloc(buffer_size);
    snprintf(numbered_lines[i], buffer_size, "%d: %s", line_number, lines[i]);
  }
  return numbered_lines;
}