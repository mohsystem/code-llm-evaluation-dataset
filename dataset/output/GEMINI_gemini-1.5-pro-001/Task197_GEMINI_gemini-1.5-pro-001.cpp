#include <random>
#include <cmath>

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center), gen(rd()), dis(0.0, 1.0) {}

    vector<double> randPoint() {
        double r = radius * sqrt(dis(gen));
        double theta = dis(gen) * 2 * M_PI;
        double x = x_center + r * cos(theta);
        double y = y_center + r * sin(theta);
        return {x, y};
    }
};