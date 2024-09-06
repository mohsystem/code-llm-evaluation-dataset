#include <stdio.h>
#include <regex.h>

int is_valid_url(const char *url) {
  regex_t regex;
  int reti;

  reti = regcomp(&regex, "^(?:http|ftp)s?://(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\\.)+(?:[A-Z]{2,6}\\.?|[A-Z0-9-]{2,}\\.?)|localhost|\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})(?::\\d+)?(?:/?|[/?]\\S+)$", REG_EXTENDED | REG_ICASE);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    return 0;
  }

  reti = regexec(&regex, url, 0, NULL, 0);
  regfree(&regex);

  if (!reti) {
    return 1;
  } else if (reti == REG_NOMATCH) {
    return 0;
  } else {
    char msgbuf[100];
    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    return 0;
  }
}

int main() {
  char url[1024];

  printf("Enter a URL: ");
  fgets(url, sizeof(url), stdin);

  if (is_valid_url(url)) {
    printf("Valid URL\n");
  } else {
    printf("Invalid URL\n");
  }

  return 0;
}