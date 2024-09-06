#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

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
    auto start = chrono::high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, x);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    ofstream myfile;
    myfile.open("execution_time.txt");
    myfile << duration.count();
    myfile.close();
    return 0;
}