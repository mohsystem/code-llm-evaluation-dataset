
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    double area = M_PI * std::pow(radius, 2);
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}
