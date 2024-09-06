#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Error: Please provide the file path as a command-line argument.\n");
    return 1;
  }

  char *file_path = argv[1];
  FILE *fp = fopen(file_path, "r");

  if (fp == NULL) {
    fprintf(stderr, "Error: Unable to open file: %s\n", file_path);
    return 1;
  }

  int c;
  while ((c = fgetc(fp)) != EOF) {
    putchar(c);
  }

  fclose(fp);
  return 0;
}