#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool solution(const char *str, const char *ending) {
  int str_len = strlen(str);
  int ending_len = strlen(ending);

  if (str_len < ending_len) {
    return false;
  }

  return strcmp(str + str_len - ending_len, ending) == 0;
}

int main() {
  printf("%d
", solution("abc", "bc")); // 1 (true)
  printf("%d
", solution("abc", "d")); // 0 (false)
  return 0;
}