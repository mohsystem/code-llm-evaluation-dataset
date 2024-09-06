#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> remove_smallest(vector<int> numbers) {
  if (numbers.empty()) {
    return numbers;
  } else {
    int min_index = distance(numbers.begin(), min_element(numbers.begin(), numbers.end()));
    numbers.erase(numbers.begin() + min_index);
    return numbers;
  }
}

int main() {
    vector<int> numbers1 = {1, 2, 3, 4, 5};
    vector<int> result1 = remove_smallest(numbers1);
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> numbers2 = {5, 3, 2, 1, 4};
    vector<int> result2 = remove_smallest(numbers2);
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> numbers3 = {2, 2, 1, 2, 1};
    vector<int> result3 = remove_smallest(numbers3);
    for (int i : result3) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}