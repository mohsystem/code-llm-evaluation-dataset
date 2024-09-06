#include <vector>
#include <algorithm>

int find_it(std::vector<int> seq) {
    for (int i : seq) {
        if (std::count(seq.begin(), seq.end(), i) % 2 != 0) {
            return i;
        }
    }
    return -1;
}