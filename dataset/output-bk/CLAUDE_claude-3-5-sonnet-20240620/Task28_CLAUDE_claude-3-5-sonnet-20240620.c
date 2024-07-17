
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* who_likes_it(size_t n, const char *const names[n]) {
    char *result = malloc(100 * sizeof(char));
    switch (n) {
        case 0:
            sprintf(result, "no one likes this");
            break;
        case 1:
            sprintf(result, "%s likes this", names[0]);
            break;
        case 2:
            sprintf(result, "%s and %s like this", names[0], names[1]);
            break;
        case 3:
            sprintf(result, "%s, %s and %s like this", names[0], names[1], names[2]);
            break;
        default:
            sprintf(result, "%s, %s and %zu others like this", names[0], names[1], n - 2);
            break;
    }
    return result;
}

int main() {
    const char *names0[] = {};
    const char *names1[] = {"Peter"};
    const char *names2[] = {"Jacob", "Alex"};
    const char *names3[] = {"Max", "John", "Mark"};
    const char *names4[] = {"Alex", "Jacob", "Mark", "Max"};

    printf("%s\
", who_likes_it(0, names0));
    printf("%s\
", who_likes_it(1, names1));
    printf("%s\
", who_likes_it(2, names2));
    printf("%s\
", who_likes_it(3, names3));
    printf("%s\
", who_likes_it(4, names4));

    return 0;
}
