#include <stdio.h>
#include <string.h>

char* whoLikesIt(char* names[], int len) {
    static char result[100];
    if (len == 0) strcpy(result, "no one likes this");
    else if (len == 1) sprintf(result, "%s likes this", names[0]);
    else if (len == 2) sprintf(result, "%s and %s like this", names[0], names[1]);
    else if (len == 3) sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
    else sprintf(result, "%s, %s and %d others like this", names[0], names[1], len - 2);
    return result;
}

int main() {
    char* names1[] = {};
    char* names2[] = {"Peter"};
    char* names3[] = {"Jacob", "Alex"};
    char* names4[] = {"Max", "John", "Mark"};
    char* names5[] = {"Alex", "Jacob", "Mark", "Max"};
    printf("%s
", whoLikesIt(names1, 0));
    printf("%s
", whoLikesIt(names2, 1));
    printf("%s
", whoLikesIt(names3, 2));
    printf("%s
", whoLikesIt(names4, 3));
    printf("%s
", whoLikesIt(names5, 4));
    return 0;
}