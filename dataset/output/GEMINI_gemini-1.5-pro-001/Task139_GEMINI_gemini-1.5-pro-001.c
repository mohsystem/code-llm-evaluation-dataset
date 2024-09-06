#include <stdio.h>
#include <math.h>

int main() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = M_PI * pow(radius, 2);
    printf("The area of the circle is: %lf\n", area);
    return 0;
}