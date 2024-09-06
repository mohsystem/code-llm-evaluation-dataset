#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tower_builder(int n_floors) {
  char **tower = (char **)malloc(n_floors * sizeof(char *));
  if (tower == NULL) {
    return NULL;
  }

  for (int i = 0; i < n_floors; i++) {
    int stars_width = 2 * i + 1;
    int spaces_width = n_floors - i - 1;
    int row_width = stars_width + 2 * spaces_width;

    tower[i] = (char *)malloc((row_width + 1) * sizeof(char));
    if (tower[i] == NULL) {
      // Clean up previously allocated memory
      for (int j = 0; j < i; j++) {
        free(tower[j]);
      }
      free(tower);
      return NULL;
    }

    // Fill the row with spaces
    memset(tower[i], ' ', row_width);
    // Place the stars in the center
    memset(tower[i] + spaces_width, '*', stars_width);
    // Add null terminator
    tower[i][row_width] = '\0';
  }

  return tower;
}