#include<iostream>
#include<vector>
using namespace std;

bool xorGame(vector<int>& nums) {
    int xorSum = 0;
    for (int num : nums) {
        xorSum ^= num;
    }
    
    return xorSum == 0 || nums.size() % 2 == 0;
}

int main() {
    // Testing example 1
    cout << boolalpha << xorGame(vector<int>{1, 1, 2}) << endl;  // False
    // Testing example 2
    cout << xorGame(vector<int>{0, 1}) << endl;  // True
    // Testing example 3
    cout << xorGame(vector<int>{1, 2, 3}) << endl;  // True
    return 0;
}