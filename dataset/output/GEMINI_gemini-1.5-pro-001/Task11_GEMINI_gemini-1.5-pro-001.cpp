#include <iostream>

using namespace std;

int nbYear(int p0, double percent, int aug, int p) {
    int years = 0;
    while (p0 < p) {
        p0 = (int) (p0 + p0 * (percent / 100) + aug);
        years++;
    }
    return years;
}
int main() {
  cout << nbYear(1500, 5, 100, 5000) << endl;
  cout << nbYear(1500000, 2.5, 10000, 2000000) << endl;
  cout << nbYear(1000, 2, 50, 1200) << endl;
  return 0;
}