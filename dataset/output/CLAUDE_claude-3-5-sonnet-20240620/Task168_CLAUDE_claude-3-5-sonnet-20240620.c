
#include <stdio.h>
#include <string.h>

void tweakLetters(char* word, int* arr, int arrSize) {
    int len = strlen(word);
    for (int i = 0; i < len && i < arrSize; i++) {
        word[i] = ((word[i] - 'a' + arr[i] + 26) % 26) + 'a';
    }
}

int main() {
    char word1[] = "apple";
    int arr1[] = {0, 1, -1, 0, -1};
    tweakLetters(word1, arr1, 5);
    printf("%s\\n", word1);

    char word2[] = "many";
    int arr2[] = {0, 0, 0, -1};
    tweakLetters(word2, arr2, 4);
    printf("%s\\n", word2);

    char word3[] = "rhino";
    int arr3[] = {1, 1, 1, 1, 1};
    tweakLetters(word3, arr3, 5);
    printf("%s\\n", word3);

    return 0;
}
