#include <iostream>
#include <vector>
using namespace std;

int findOdd(vector<int> arr) {
    for (int num : arr) {
        int count = 0;
        for (int i : arr) {
            if (i == num) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return num;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    cout << findOdd(arr) << endl;
    return 0;
}