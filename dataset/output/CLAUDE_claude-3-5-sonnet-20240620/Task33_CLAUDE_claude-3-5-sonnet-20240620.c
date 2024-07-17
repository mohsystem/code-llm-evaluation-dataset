
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int queueTime(const int *customers, int customersLength, int n) {
    if (customersLength == 0) return 0;
    if (n >= customersLength) return customers[0];
    
    int *tills = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < customersLength; i++) {
        tills[0] += customers[i];
        qsort(tills, n, sizeof(int), compare);
    }
    
    int maxTime = tills[n-1];
    free(tills);
    return maxTime;
}
