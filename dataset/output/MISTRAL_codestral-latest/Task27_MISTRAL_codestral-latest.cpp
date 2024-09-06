#include <vector>
int find_outlier(std::vector<int> integers) {
    int evens = 0, odds = 0, even = 0, odd = 0;
    for (int i = 0; i < integers.size(); i++) {
        if (integers[i] % 2 == 0) {
            evens++;
            even = integers[i];
        } else {
            odds++;
            odd = integers[i];
        }
    }
    return evens < odds ? even : odd;
}