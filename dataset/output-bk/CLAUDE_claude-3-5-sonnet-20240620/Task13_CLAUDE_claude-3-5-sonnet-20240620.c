
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char *walk) {
    if (strlen(walk) != 10) return false;
    
    int x = 0, y = 0;
    for (int i = 0; walk[i] != \'\\0\'; i++) {
        switch (walk[i]) {
            case \'n\': y++; break;
            case \'s\': y--; break;
            case \'e\': x++; break;
            case \'w\': x--; break;
        }
    }
    
    return x == 0 && y == 0;
}

int main() {
    printf("%d\
", isValidWalk("nsnsnsnsns")); // 1 (true)
    printf("%d\
", isValidWalk("wewewewewewe")); // 0 (false)
    printf("%d\
", isValidWalk("w")); // 0 (false)
    printf("%d\
", isValidWalk("nnnsnsnsns")); // 0 (false)
    return 0;
}
