#include <stdio.h>
#include <math.h>

int main() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = M_PI * radius * radius;
    printf("The area of the circle is: %.2lf
", area);
    return 0;
}