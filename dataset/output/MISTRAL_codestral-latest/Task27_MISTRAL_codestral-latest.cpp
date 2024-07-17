#include <vector>

int find_outlier(std::vector<int> arr) {
    int even = 0, odd = 0;
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            even = arr[i];
            even_count++;
        } else {
            odd = arr[i];
            odd_count++;
        }
    }

    return (even_count < odd_count) ? even : odd;
}