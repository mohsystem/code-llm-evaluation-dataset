
#include <stdio.h>
#include <math.h>

int main() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = M_PI * pow(radius, 2);
    printf("The area of the circle is: %.2f\\n", area);
    return 0;
}
