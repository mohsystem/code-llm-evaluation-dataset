#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                return { i, j };
            }
        }
    }
    return {};
}

int main() {
    vector<int> result = twoSum({1, 2, 3}, 4);
    cout << "{" << result[0] << ", " << result[1] << "}" << endl;
    
    result = twoSum({3, 2, 4}, 6);
    cout << "{" << result[0] << ", " << result[1] << "}" << endl;

    return 0;
}