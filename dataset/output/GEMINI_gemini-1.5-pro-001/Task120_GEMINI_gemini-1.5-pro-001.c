#include <stdio.h>

int main() {
  char userInput[100];

  printf("Enter some text: ");
  fgets(userInput, sizeof(userInput), stdin);

  printf("<!DOCTYPE html>
");
  printf("<html>
");
  printf("<head><title>User Input</title></head>
");
  printf("<body>
");
  printf("<h1>You entered: %s</h1>
", userInput);
  printf("</body>
");
  printf("</html>
");

  return 0;
}