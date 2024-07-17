#include <algorithm>
#include <vector>

int longestRun(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    int longestSequence = 1;
    int currentSequence = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
            currentSequence++;
        } else {
            longestSequence = std::max(longestSequence, currentSequence);
            currentSequence = 1;
        }
    }

    return std::max(longestSequence, currentSequence);
}