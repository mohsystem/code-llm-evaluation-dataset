
#include <stdio.h>

int findEvenIndex(int arr[], int size) {
    int leftSum = 0;
    int rightSum = 0;
    
    for (int i = 0; i < size; i++) {
        rightSum += arr[i];
    }
    
    for (int i = 0; i < size; i++) {
        rightSum -= arr[i];
        
        if (leftSum == rightSum) {
            return i;
        }
        
        leftSum += arr[i];
    }
    
    return -1;
}

int main() {
    int arr1[] = {1,2,3,4,3,2,1};
    int arr2[] = {1,100,50,-51,1,1};
    int arr3[] = {20,10,-80,10,10,15,35};
    
    printf("%d\
", findEvenIndex(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("%d\
", findEvenIndex(arr2, sizeof(arr2)/sizeof(arr2[0])));
    printf("%d\
", findEvenIndex(arr3, sizeof(arr3)/sizeof(arr3[0])));
    
    return 0;
}
