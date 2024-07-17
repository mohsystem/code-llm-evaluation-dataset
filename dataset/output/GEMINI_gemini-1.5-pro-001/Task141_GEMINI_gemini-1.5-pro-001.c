#include <stdio.h>
#include <string.h>

void reverse_string(char* str) {
  char *end = str + strlen(str) - 1;
  char temp;
  while (end > str) {
    temp = *str;
    *str++ = *end;
    *end-- = temp;
  }
}

int main() {
  char inputString[100];
  printf("Enter a string: ");
  fgets(inputString, sizeof(inputString), stdin);
  inputString[strcspn(inputString, "
")] = 0; 
  reverse_string(inputString);
  printf("%s
", inputString);
  return 0;
}