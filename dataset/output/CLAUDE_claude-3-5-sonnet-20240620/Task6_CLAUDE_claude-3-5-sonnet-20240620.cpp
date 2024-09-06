
#include <vector>
#include <iostream>
#include <algorithm>

double findUniq(const std::vector<double> &v) {
    if (v[0] != v[1] && v[0] != v[2]) return v[0];
    return *std::find_if(v.begin(), v.end(), [&](double x) { return x != v[0]; });
}

int main() {
    std::cout << findUniq({1, 1, 1, 2, 1, 1}) << std::endl;  // Output: 2
    std::cout << findUniq({0, 0, 0.55, 0, 0}) << std::endl;  // Output: 0.55
    return 0;
}
