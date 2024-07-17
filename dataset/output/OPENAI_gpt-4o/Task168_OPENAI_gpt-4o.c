#include <stdio.h>
#include <string.h>

void tweakLetters(char* txt, int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        txt[i] = txt[i] + arr[i];
    }
}

int main() {
    char txt1[] = "apple";
    int arr1[] = {0, 1, -1, 0, -1};
    tweakLetters(txt1, arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("%s
", txt1);

    char txt2[] = "many";
    int arr2[] = {0, 0, 0, -1};
    tweakLetters(txt2, arr2, sizeof(arr2) / sizeof(arr2[0]));
    printf("%s
", txt2);

    char txt3[] = "rhino";
    int arr3[] = {1, 1, 1, 1, 1};
    tweakLetters(txt3, arr3, sizeof(arr3) / sizeof(arr3[0]));
    printf("%s
", txt3);

    return 0;
}