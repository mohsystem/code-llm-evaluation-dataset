
#include <stdio.h>
#include <string.h>

char* likes(const char* names[], int count) {
    static char result[100];

    switch (count) {
        case 0:
            strcpy(result, "no one likes this");
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
            sprintf(result, "%s, %s and %d others like this", names[0], names[1], count - 2);
            break;
    }

    return result;
}

int main() {
    const char* names0[] = {};
    const char* names1[] = {"Peter"};
    const char* names2[] = {"Jacob", "Alex"};
    const char* names3[] = {"Max", "John", "Mark"};
    const char* names4[] = {"Alex", "Jacob", "Mark", "Max"};

    printf("%s\\n", likes(names0, 0));
    printf("%s\\n", likes(names1, 1));
    printf("%s\\n", likes(names2, 2));
    printf("%s\\n", likes(names3, 3));
    printf("%s\\n", likes(names4, 4));

    return 0;
}
