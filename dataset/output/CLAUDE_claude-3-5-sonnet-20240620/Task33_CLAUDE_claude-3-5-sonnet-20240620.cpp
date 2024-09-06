
#include <algorithm>
#include <vector>

class Solution {
public:
    static int queueTime(std::vector<int> customers, int n) {
        std::vector<int> tills(n, 0);
        for (int customer : customers) {
            tills[0] += customer;
            std::sort(tills.begin(), tills.end());
        }
        return *std::max_element(tills.begin(), tills.end());
    }
};
