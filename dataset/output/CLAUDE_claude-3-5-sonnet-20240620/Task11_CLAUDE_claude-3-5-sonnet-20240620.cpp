
#include <iostream>

int nb_year(int p0, double percent, int aug, int p) {
    int years = 0;
    int population = p0;
    
    while (population < p) {
        population += (int)(population * percent / 100) + aug;
        years++;
    }
    
    return years;
}

int main() {
    std::cout << nb_year(1500, 5, 100, 5000) << std::endl;
    std::cout << nb_year(1500000, 2.5, 10000, 2000000) << std::endl;
    return 0;
}
