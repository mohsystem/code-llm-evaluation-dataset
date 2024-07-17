#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int is_valid_command(const char *command) {
  for (int i = 0; command[i] != '\0'; i++) {
    if (!isalnum(command[i]) && !isspace(command[i]) && 
        strchr("./_-", command[i]) == NULL) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char command[1024];
  
  printf("Enter a bash command: ");
  fgets(command, sizeof(command), stdin);

  // Remove trailing newline from fgets
  command[strcspn(command, "
")] = 0;

  if (is_valid_command(command)) {
    int result = system(command);
    if (result != 0) {
      fprintf(stderr, "Error executing command: %s
", command);
    }
  } else {
    printf("Invalid command format. Please use only alphanumeric characters, spaces, and './-_' 
");
  }

  return 0;
}