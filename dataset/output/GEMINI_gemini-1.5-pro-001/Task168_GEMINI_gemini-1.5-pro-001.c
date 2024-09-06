#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* tweakLetters(char* txt, int arr[], int size) {
  char* res = (char*) malloc(sizeof(char) * (strlen(txt) + 1));
  for (int i = 0; i < strlen(txt); i++) {
    if (arr[i] == 1) {
      res[i] = txt[i] + 1;
    } else if (arr[i] == -1) {
      res[i] = txt[i] - 1;
    } else {
      res[i] = txt[i];
    }
  }
  res[strlen(txt)] = '\0';
  return res;
}

int main() {
  // test the code
  int arr1[] = {0, 1, -1, 0, -1};
  char* result1 = tweakLetters("apple", arr1, 5);
  printf("%s\n", result1);
  free(result1);

  int arr2[] = {0, 0, 0, -1};
  char* result2 = tweakLetters("many", arr2, 4);
  printf("%s\n", result2);
  free(result2);

  int arr3[] = {1, 1, 1, 1, 1};
  char* result3 = tweakLetters("rhino", arr3, 5);
  printf("%s\n", result3);
  free(result3);

  return 0;
}