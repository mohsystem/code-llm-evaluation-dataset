#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
int main() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = M_PI * (radius * radius);
    printf("The area of the circle is: %f\n", area);
    return 0;
}