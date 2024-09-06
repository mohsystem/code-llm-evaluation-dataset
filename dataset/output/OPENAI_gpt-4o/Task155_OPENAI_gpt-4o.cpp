#include <iostream>
#include <vector>

using namespace std;

class Sorting {
public:
    static void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void heapSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    Sorting::heapSort(arr);
    cout << "Sorted array is: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}