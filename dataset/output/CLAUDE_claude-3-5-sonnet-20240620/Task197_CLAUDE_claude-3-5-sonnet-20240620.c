
#include <stdlib.h>
#include <math.h>

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
    double angle = ((double)rand() / RAND_MAX) * 2 * M_PI;
    double r = obj->radius * sqrt((double)rand() / RAND_MAX);
    double x = obj->x_center + r * cos(angle);
    double y = obj->y_center + r * sin(angle);
    
    double* result = (double*) malloc(2 * sizeof(double));
    result[0] = x;
    result[1] = y;
    *retSize = 2;
    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(radius, x_center, y_center);
 * double* param_1 = solutionRandPoint(obj, retSize);
 * solutionFree(obj);
*/
