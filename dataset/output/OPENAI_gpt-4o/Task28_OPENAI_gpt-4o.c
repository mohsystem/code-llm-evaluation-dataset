#include <stdio.h>
#include <string.h>

char* whoLikesIt(int count, char *names[]) {
    static char result[100];
    if (count == 0) {
        strcpy(result, "no one likes this");
    } else if (count == 1) {
        sprintf(result, "%s likes this", names[0]);
    } else if (count == 2) {
        sprintf(result, "%s and %s like this", names[0], names[1]);
    } else if (count == 3) {
        sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
    } else {
        sprintf(result, "%s, %s and %d others like this", names[0], names[1], count - 2);
    }
    return result;
}

int main() {
    char *names[] = {"Alex", "Jacob", "Mark", "Max"};
    int count = 4;
    printf("%s
", whoLikesIt(count, names));
    return 0;
}