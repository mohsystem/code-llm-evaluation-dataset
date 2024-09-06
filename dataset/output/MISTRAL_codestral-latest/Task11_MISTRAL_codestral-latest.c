#include <stdio.h>

int nbYear(int p0, double percent, int aug, int p) {
    int years = 0;
    while (p0 < p) {
        p0 = p0 + p0 * (percent / 100) + aug;
        years++;
    }
    return years;
}