#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> mergedArray;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            mergedArray.push_back(arr1[i++]);
        } else {
            mergedArray.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        mergedArray.push_back(arr2[j++]);
    }
    return mergedArray;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);
    cout << "Merged array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}