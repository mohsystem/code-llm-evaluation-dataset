#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> P(n + 1);
    for (int i = 0; i < n; ++i)
        P[i + 1] = P[i] + nums[i];

    int ans = n + 1;
    deque<int> monoq;
    for (int y = 0; y < P.size(); ++y) {
        while (!monoq.empty() && P[y] <= P[monoq.back()])
            monoq.pop_back();

        while (!monoq.empty() && P[y] >= P[monoq.front()] + k)
            ans = min(ans, y - monoq.front()), monoq.pop_front();

        monoq.push_back(y);
    }

    return ans < n + 1 ? ans : -1;
}

int main() {
    cout << shortestSubarray(vector<int>{1}, 1) << endl; // Output: 1
    cout << shortestSubarray(vector<int>{1, 2}, 4) << endl; // Output: -1
    cout << shortestSubarray(vector<int>{2, -1, 2}, 3) << endl; // Output: 3
    return 0;
}