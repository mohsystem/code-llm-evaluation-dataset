// CPP
#include <cstdlib>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (true) {
        int a = rand7();
        int b = rand7();
        int num = (a - 1) * 7 + b;
        if (num <= 40) {
            return 1 + (num - 1) % 10;
        }
    }
}