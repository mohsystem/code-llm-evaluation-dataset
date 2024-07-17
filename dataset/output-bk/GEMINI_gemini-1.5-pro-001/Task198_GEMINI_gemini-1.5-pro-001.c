#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rand7() {
    return rand() % 7 + 1;
}
int rand10() {
    while (1) {
        int row = rand7();
        int col = rand7();
        int idx = col + (row - 1) * 7;
        if (idx <= 40) {
            return 1 + (idx - 1) % 10;
        }
    }
}
int main() {
    srand(time(NULL));
    // Example usage
    int n = 3;
    for (int i = 0; i < n; i++) {
        printf("%d ", rand10());
    }
    printf("
");
    return 0;
}