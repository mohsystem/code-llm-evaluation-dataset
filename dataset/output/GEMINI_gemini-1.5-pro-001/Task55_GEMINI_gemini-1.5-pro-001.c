#include <stdio.h>
#include <regex.h>

int isValidEmail(const char *email) {
  regex_t regex;
  int result;

  // Compile the regular expression
  result = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);
  if (result) {
    return 0; // Failed to compile
  }

  // Match the email against the regex
  result = regexec(&regex, email, 0, NULL, 0);
  regfree(&regex);

  return result == 0; // 0 means match, non-zero means no match
}

int main() {
  char email[256];
  printf("Enter an email address: ");
  fgets(email, sizeof(email), stdin);
  email[strcspn(email, "\n")] = 0; // Remove trailing newline

  if (isValidEmail(email)) {
    printf("Valid email address\n");
  } else {
    printf("Invalid email address\n");
  }

  return 0;
}