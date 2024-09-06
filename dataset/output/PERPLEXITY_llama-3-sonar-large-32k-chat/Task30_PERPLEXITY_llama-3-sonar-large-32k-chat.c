#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge_and_sort(char* a, char* b, char* result) {
    int i, j, k = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_result = len_a + len_b;
    char* temp = (char*)malloc(len_result * sizeof(char));
    for (i = 0; i < len_a; i++) temp[k++] = a[i];
    for (i = 0; i < len_b; i++) temp[k++] = b[i];
    for (i = 0; i < len_result; i++) {
        for (j = i + 1; j < len_result; j++) {
            if (temp[i] > temp[j]) {
                char t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    k = 0;
    for (i = 0; i < len_result; i++) {
        if (i == 0 || temp[i] != temp[i - 1]) {
            result[k++] = temp[i];
        }
    }
    result[k] = '\0';
    free(temp);
}

int main() {
    char a[] = "xyaabbbccccdefww";
    char b[] = "xxxxyyyyabklmopq";
    char result[100];
    merge_and_sort(a, b, result);
    printf("%s\n", result);
    char a2[] = "abcdefghijklmnopqrstuvwxyz";
    char b2[] = "abcdefghijklmnopqrstuvwxyz";
    char result2[100];
    merge_and_sort(a2, b2, result2);
    printf("%s\n", result2);
    return 0;
}