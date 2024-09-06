#include <vector>
#include <algorithm>

class Kata {
public:
    static double findUniq(std::vector<double> arr) {
        std::sort(arr.begin(), arr.end());
        return (arr[0] == arr[1]) ? arr.back() : arr[0];
    }
}