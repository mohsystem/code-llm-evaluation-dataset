extern "C" {
    #include <stdlib.h>
    
    int find_kth_largest(int arr[], int n, int k);
}

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    
    int result = find_kth_largest(arr, n, k);
    cout << result << endl;
    
    delete[] arr;
    return 0;
}