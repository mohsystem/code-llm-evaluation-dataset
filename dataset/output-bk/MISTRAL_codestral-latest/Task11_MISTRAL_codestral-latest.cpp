// C++
#include <iostream>

int nb_year(int p0, double percent, int aug, int p) {
    int years = 0;
    while (p0 < p) {
        p0 += p0 * percent / 100 + aug;
        years++;
    }
    return years;
}

int main() {
    std::cout << nb_year(1500, 5, 100, 5000);
    return 0;
}