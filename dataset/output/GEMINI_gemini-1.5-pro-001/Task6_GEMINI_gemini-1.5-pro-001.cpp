#include <vector>
#include <algorithm>

using namespace std;

double findUniq(const vector<double> &arr) {
    sort(arr.begin(), arr.end());
    return arr[0] == arr[1] ? arr[arr.size()-1] : arr[0];
}