#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* sol = (Solution*) malloc(sizeof(Solution));
    sol->radius = radius;
    sol->x_center = x_center;
    sol->y_center = y_center;
    srand(time(0));
    return sol;
}

void randPoint(Solution* sol, double *point) {
    double r = sol->radius * sqrt((double) rand() / RAND_MAX);
    double theta = 2 * M_PI * ((double) rand() / RAND_MAX);
    point[0] = sol->x_center + r * cos(theta);
    point[1] = sol->y_center + r * sin(theta);
}

int main() {
    Solution* sol = solutionCreate(1.0, 0.0, 0.0);
    double point[2];

    randPoint(sol, point);
    printf("Point1: [%f, %f]\n", point[0], point[1]);
    randPoint(sol, point);
    printf("Point2: [%f, %f]\n", point[0], point[1]);
    randPoint(sol, point);
    printf("Point3: [%f, %f]\n", point[0], point[1]);

    free(sol);
    return 0;
}