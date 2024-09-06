#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    vector<int> sortedList;
    for (int i = nums.size() - 1; i >= 0; i--) {
        auto it = lower_bound(sortedList.begin(), sortedList.end(), nums[i]);
        result[i] = distance(sortedList.begin(), it);
        sortedList.insert(it, nums[i]);
    }
    return result;
}

int main() {
    vector<int> nums;
    int input;
    while (cin >> input) {
        nums.push_back(input);
        if (cin.peek() == '\n') break;
    }
    vector<int> result = countSmaller(nums);
    for (int count : result) {
        cout << count << " ";
    }
    return 0;
}