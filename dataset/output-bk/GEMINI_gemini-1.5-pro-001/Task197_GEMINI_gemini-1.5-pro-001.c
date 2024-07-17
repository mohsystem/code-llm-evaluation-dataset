#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double radius;
    double x_center;
    double y_center;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* obj = (Solution*) malloc(sizeof(Solution));
    obj->radius = radius;
    obj->x_center = x_center;
    obj->y_center = y_center;
    srand(time(NULL));
    return obj;
}

double* solutionRandPoint(Solution* obj, int* retSize) {
    double r = obj->radius * sqrt(((double) rand() / (RAND_MAX)));
    double theta = ((double) rand() / (RAND_MAX)) * 2 * M_PI;
    double* point = (double*) malloc(2 * sizeof(double));
    point[0] = obj->x_center + r * cos(theta);
    point[1] = obj->y_center + r * sin(theta);
    *retSize = 2;
    return point;
}

void solutionFree(Solution* obj) {
    free(obj);
}