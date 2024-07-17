#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;
    srand(time(0));
    return obj;
}

double* randPoint(Solution* obj) {
    double* point = (double*)malloc(2 * sizeof(double));
    double angle = ((double) rand() / RAND_MAX) * 2 * M_PI;
    double hyp = sqrt((double) rand() / RAND_MAX) * obj->radius;
    point[0] = obj->x_center + hyp * cos(angle);
    point[1] = obj->y_center + hyp * sin(angle);
    return point;
}

void solutionFree(Solution* obj) {
    free(obj);
}