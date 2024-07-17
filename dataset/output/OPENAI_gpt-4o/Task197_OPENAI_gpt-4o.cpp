#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

class Solution {
private:
    double radius;
    double x_center;
    double y_center;

public:
    Solution(double radius, double x_center, double y_center) 
        : radius(radius), x_center(x_center), y_center(y_center) {
        srand(time(0));
    }

    std::vector<double> randPoint() {
        double angle = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double hyp = sqrt((double) rand() / RAND_MAX) * radius;
        double x = x_center + hyp * cos(angle);
        double y = y_center + hyp * sin(angle);
        return {x, y};
    }
};