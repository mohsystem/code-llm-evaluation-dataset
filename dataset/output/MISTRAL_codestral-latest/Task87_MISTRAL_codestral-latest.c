#include<stdio.h>
#include<time.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 10, 12, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int result = binarySearch(arr, 0, n - 1, x);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    FILE *f = fopen("execution_time.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(f, "%f", cpu_time_used);
    fclose(f);
    return 0;
}