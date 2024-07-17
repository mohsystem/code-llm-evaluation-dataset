#include <stdio.h>

int nb_year(int p0, double percent, int aug, int p) {
    int years = 0;
    while (p0 < p) {
        p0 += (int)(p0 * percent / 100) + aug;
        years++;
    }
    return years;
}

int main() {
    printf("%d
", nb_year(1000, 2, 50, 1200)); // 3
    printf("%d
", nb_year(1500, 5, 100, 5000)); // 15
    printf("%d
", nb_year(1500000, 2.5, 10000, 2000000)); // 10
    return 0;
}