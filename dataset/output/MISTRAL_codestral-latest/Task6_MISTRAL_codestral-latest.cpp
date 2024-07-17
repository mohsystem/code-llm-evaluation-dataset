// C++
#include <vector>

double findUniq(std::vector<double> arr) {
    double a = arr[0];
    double b = arr[1];
    double c = arr[2];

    if (a != b && a != c) return a;
    if (a != b) return c;

    for (int i = 3; i < arr.size(); i++) {
        if (arr[i] != a) return arr[i];
    }

    return -1;
}