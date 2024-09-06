
#include <cmath>
#include <iomanip>

class Solution {
public:
    static double cubeDiagonal(double volume) {
        double side = std::cbrt(volume);
        double diagonal = std::sqrt(3) * side;
        return std::round(diagonal * 100.0) / 100.0;
    }
};
