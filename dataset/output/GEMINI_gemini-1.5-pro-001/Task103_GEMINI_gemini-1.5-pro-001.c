#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(char *password) {
  if (strlen(password) < 8) {
    return 0;
  }
  int hasUpper = 0;
  int hasLower = 0;
  int hasDigit = 0;
  for (int i = 0; password[i] != '\0'; i++) {
    if (isupper(password[i])) {
      hasUpper = 1;
    } else if (islower(password[i])) {
      hasLower = 1;
    } else if (isdigit(password[i])) {
      hasDigit = 1;
    }
  }
  return hasUpper && hasLower && hasDigit;
}

int main() {
  char password[100];
  printf("Enter a password: ");
  fgets(password, sizeof(password), stdin);
  password[strcspn(password, "\n")] = 0; 

  if (checkPasswordStrength(password)) {
    printf("Strong password\n");
  } else {
    printf("Weak password\n");
  }
  return 0;
}