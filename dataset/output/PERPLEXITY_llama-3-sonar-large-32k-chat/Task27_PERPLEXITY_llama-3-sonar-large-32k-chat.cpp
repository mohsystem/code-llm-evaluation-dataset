#include <vector>
using namespace std;

int find(vector<int> integers) {
    int even = 0, odd = 0, evenCount = 0, oddCount = 0;
    for (int num : integers) {
        if (num % 2 == 0) {
            even = num;
            evenCount++;
        } else {
            odd = num;
            oddCount++;
        }
    }
    return evenCount == 1 ? even : odd;
}