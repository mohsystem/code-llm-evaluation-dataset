#include <stdio.h>

int main() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = 3.14159 * radius * radius;
    printf("Area of the circle is: %lf
", area);
    return 0;
}