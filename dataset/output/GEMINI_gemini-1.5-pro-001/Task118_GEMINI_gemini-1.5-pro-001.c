#include <stdio.h>
#include <regex.h>
#include <string.h>

int isValidIP(const char *ip) {
  regex_t regex;
  int reti;

  reti = regcomp(&regex, "^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$", REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    return 0;
  }

  reti = regexec(&regex, ip, 0, NULL, 0);
  regfree(&regex);

  return reti == 0;
}

int main() {
  char ipAddress[16];

  printf("Enter an IP address: ");
  fgets(ipAddress, sizeof(ipAddress), stdin);
  ipAddress[strcspn(ipAddress, "\n")] = 0; // remove trailing newline

  if (isValidIP(ipAddress)) {
    printf("Valid IP address\n");
  } else {
    printf("Invalid IP address\n");
  }

  return 0;
}