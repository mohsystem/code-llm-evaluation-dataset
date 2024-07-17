#include <stdlib.h>
#include <math.h>

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
    return obj;
}

double* solutionRandPoint(Solution* obj, int* retSize) {
    double* ret = malloc(sizeof(double) * 2);
    *retSize = 2;
    double r = obj->radius * sqrt((double)rand() / RAND_MAX);
    double theta = (double)rand() / RAND_MAX * 2 * M_PI;
    ret[0] = obj->x_center + r * cos(theta);
    ret[1] = obj->y_center + r * sin(theta);
    return ret;
}

void solutionFree(Solution* obj) {
    free(obj);
}