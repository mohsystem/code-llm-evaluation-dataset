
#include <cmath>
#include <random>

class Solution {
private:
    double radius;
    double x_center;
    double y_center;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

public:
    Solution(double radius, double x_center, double y_center) 
        : radius(radius), x_center(x_center), y_center(y_center), 
          gen(std::random_device{}()), dis(0.0, 1.0) {}
    
    vector<double> randPoint() {
        double angle = dis(gen) * 2 * M_PI;
        double r = radius * sqrt(dis(gen));
        double x = x_center + r * cos(angle);
        double y = y_center + r * sin(angle);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
