
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::vector<int> filter_list(const std::vector<int>& l) {
        std::vector<int> result;
        std::copy_if(l.begin(), l.end(), std::back_inserter(result),
                     [](const auto& elem) { return std::is_integral<decltype(elem)>::value; });
        return result;
    }
};
