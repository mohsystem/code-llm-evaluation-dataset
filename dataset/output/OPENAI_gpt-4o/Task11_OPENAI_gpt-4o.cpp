#include <iostream>
using namespace std;

int nb_year(int p0, double percent, int aug, int p) {
    int year = 0;
    while (p0 < p) {
        p0 += static_cast<int>(p0 * percent / 100.0) + aug;
        year += 1;
    }
    return year;
}

int main() {
    cout << nb_year(1000, 2, 50, 1200) << endl;  // Example usage
    return 0;
}