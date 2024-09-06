#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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
        std::srand(std::time(0));
    }

    std::pair<double, double> randPoint() {
        double r = radius * std::sqrt((double) std::rand() / RAND_MAX);
        double theta = 2 * M_PI * ((double) std::rand() / RAND_MAX);
        double x = x_center + r * cos(theta);
        double y = y_center + r * sin(theta);
        return {x, y};
    }
};

int main() {
    Solution sol(1.0, 0.0, 0.0);
    auto point1 = sol.randPoint();
    auto point2 = sol.randPoint();
    auto point3 = sol.randPoint();
    std::cout << "Point1: [" << point1.first << ", " << point1.second << "]\n";
    std::cout << "Point2: [" << point2.first << ", " << point2.second << "]\n";
    std::cout << "Point3: [" << point3.first << ", " << point3.second << "]\n";
    return 0;
}