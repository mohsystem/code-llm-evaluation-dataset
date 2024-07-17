#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    // if we reach here, then element was not present
    return -1;
}

int main() {
    ofstream outFile;
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, x);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    outFile.open("execution_time.txt");
    outFile << "Execution time in nanoseconds: " << duration.count() << endl;
    outFile.close();

    if (result == -1)
        cout << "Element not present" << endl;
    else
        cout << "Element found at index " << result << endl;

    return 0;
}