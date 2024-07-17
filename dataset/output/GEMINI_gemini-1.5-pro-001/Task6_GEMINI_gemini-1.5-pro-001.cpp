#include <iostream>
#include <vector>

using namespace std;

double findUniq(const vector<double>& arr) {
    if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] != arr[i - 1]) return arr[i];
    return 0;
}