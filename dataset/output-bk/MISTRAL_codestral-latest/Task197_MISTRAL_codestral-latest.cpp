#include <random>
#include <cmath>
#include <vector>

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dis;

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center), gen(std::random_device{}()) {
        dis = std::uniform_real_distribution<double>(0, 1);
    }

    std::vector<double> randPoint() {
        double r = this->radius * std::sqrt(dis(gen));
        double theta = dis(gen) * 2 * M_PI;
        double x = this->x_center + r * std::cos(theta);
        double y = this->y_center + r * std::sin(theta);
        return {x, y};
    }
};