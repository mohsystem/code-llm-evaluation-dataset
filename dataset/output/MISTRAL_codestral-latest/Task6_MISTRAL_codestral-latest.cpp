#include <vector>
#include <unordered_map>

double findUniq(std::vector<double> arr) {
    std::unordered_map<double, int> count;
    for (double num : arr) {
        count[num]++;
    }
    for (auto const& entry : count) {
        if (entry.second == 1) {
            return entry.first;
        }
    }
    return 0;
}