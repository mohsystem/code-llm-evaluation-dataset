#include <random>

class Solution {
private:
    double radius;
    double xCenter;
    double yCenter;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dist;

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), xCenter(x_center), yCenter(y_center), gen(rd()), dist(0.0, 1.0) {}

    vector<double> randPoint() {
        double angle = dist(gen) * 2 * M_PI;
        double r = sqrt(dist(gen)) * radius;
        double x = xCenter + r * cos(angle);
        double y = yCenter + r * sin(angle);
        return {x, y};
    }
};