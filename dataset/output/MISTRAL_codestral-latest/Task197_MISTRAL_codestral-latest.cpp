#include <cmath>
#include <cstdlib>
#include <vector>

class Solution {
private:
    double radius;
    double x_center;
    double y_center;

public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }

    std::vector<double> randPoint() {
        double r = radius * sqrt((double)rand() / RAND_MAX);
        double theta = (double)rand() / RAND_MAX * 2 * M_PI;
        double x = x_center + r * cos(theta);
        double y = y_center + r * sin(theta);
        return {x, y};
    }
};