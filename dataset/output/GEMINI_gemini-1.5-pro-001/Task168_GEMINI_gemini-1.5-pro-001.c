#include <string.h>

char * tweakLetters(char * txt, int arr[], int arr_size) {
  char * newTxt = (char *) malloc(strlen(txt) + 1);
  strcpy(newTxt, txt);
  for (int i = 0; i < strlen(txt); i++) {
    if (arr[i] == 1) {
      newTxt[i] = (char) (txt[i] + 1);
    } else if (arr[i] == -1) {
      newTxt[i] = (char) (txt[i] - 1);
    } else {
      newTxt[i] = txt[i];
    }
  }
  return newTxt;
}