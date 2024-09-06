#include <stdio.h>
#include <string.h>

const char* likes(int count, const char* names[]) {
    static char buffer[256];
    switch (count) {
        case 0: strcpy(buffer, "no one likes this"); break;
        case 1: sprintf(buffer, "%s likes this", names[0]); break;
        case 2: sprintf(buffer, "%s and %s like this", names[0], names[1]); break;
        case 3: sprintf(buffer, "%s, %s and %s like this", names[0], names[1], names[2]); break;
        default: sprintf(buffer, "%s, %s and %d others like this", names[0], names[1], count - 2); break;
    }
    return buffer;
}

int main() {
    const char* names1[] = {};
    const char* names2[] = {"Peter"};
    const char* names3[] = {"Jacob", "Alex"};
    const char* names4[] = {"Max", "John", "Mark"};
    const char* names5[] = {"Alex", "Jacob", "Mark", "Max"};

    printf("%s\n", likes(0, names1));
    printf("%s\n", likes(1, names2));
    printf("%s\n", likes(2, names3));
    printf("%s\n", likes(3, names4));
    printf("%s\n", likes(4, names5));

    return 0;
}