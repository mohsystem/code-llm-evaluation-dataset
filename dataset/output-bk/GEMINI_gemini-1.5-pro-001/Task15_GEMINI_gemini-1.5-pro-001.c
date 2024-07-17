#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **tower_builder(int n_floors) {
  char **tower = malloc(n_floors * sizeof(char *));
  
  for (int i = 0; i < n_floors; i++) {
    int stars = 2 * i + 1;
    int spaces = n_floors - i - 1;
    
    tower[i] = malloc((stars + 2 * spaces + 1) * sizeof(char)); // +1 for null terminator
    
    memset(tower[i], ' ', spaces);
    memset(tower[i] + spaces, '*', stars);
    memset(tower[i] + spaces + stars, ' ', spaces);
    tower[i][stars + 2 * spaces] = '\0';
  }
  
  return tower;
}

int main() {
  int n_floors = 3;
  char **tower = tower_builder(n_floors);

  for (int i = 0; i < n_floors; i++) {
    printf("\"%s\"
", tower[i]);
    free(tower[i]);
  }
  free(tower);

  return 0;
}