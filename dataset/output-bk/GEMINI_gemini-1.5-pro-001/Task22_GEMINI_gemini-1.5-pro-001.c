#include <stdio.h>
#include <stdlib.h>

int is_integer(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (i == 0 && (str[i] == '-' || str[i] == '+')) {
      continue;
    }
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  return 1;
}

int main() {
  char *list1[] = {"1", "2", "a", "b"};
  int len1 = sizeof(list1) / sizeof(list1[0]);
  for (int i = 0; i < len1; i++) {
    if (is_integer(list1[i])) {
      printf("%s ", list1[i]);
    }
  }
  printf("
");

  char *list2[] = {"1", "a", "b", "0", "15"};
  int len2 = sizeof(list2) / sizeof(list2[0]);
  for (int i = 0; i < len2; i++) {
    if (is_integer(list2[i])) {
      printf("%s ", list2[i]);
    }
  }
  printf("
");

  char *list3[] = {"1", "2", "a", "b", "aasf", "1", "123", "123"};
  int len3 = sizeof(list3) / sizeof(list3[0]);
  for (int i = 0; i < len3; i++) {
    if (is_integer(list3[i])) {
      printf("%s ", list3[i]);
    }
  }
  printf("
");

  return 0;
}