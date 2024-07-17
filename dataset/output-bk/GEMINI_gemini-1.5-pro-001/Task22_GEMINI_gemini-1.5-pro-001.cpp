#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> filter_list(const vector<string>& list) {
  vector<int> result;
  for (const auto& element : list) {
    if (all_of(element.begin(), element.end(), ::isdigit)) {
      result.push_back(stoi(element));
    }
  }
  return result;
}

int main() {
  vector<string> list1 = {"1", "2", "a", "b"};
  vector<int> filtered1 = filter_list(list1);
  for (int i : filtered1) {
    cout << i << " ";
  }
  cout << endl;

  vector<string> list2 = {"1", "a", "b", "0", "15"};
  vector<int> filtered2 = filter_list(list2);
  for (int i : filtered2) {
    cout << i << " ";
  }
  cout << endl;

  vector<string> list3 = {"1", "2", "a", "b", "aasf", "1", "123", "123"};
  vector<int> filtered3 = filter_list(list3);
  for (int i : filtered3) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}