#include <iostream>
using namespace std;

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    double area = 3.14159 * radius * radius;
    cout << "Area of the circle is: " << area << endl;
    return 0;
}