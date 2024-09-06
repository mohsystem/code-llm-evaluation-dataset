#include <iostream>
#include <vector>
#include <variant>

using namespace std;

vector<int> filterList(vector<variant<int, string>> list) {
    vector<int> result;
    for (const auto& item : list) {
        if (holds_alternative<int>(item)) {
            result.push_back(get<int>(item));
        }
    }
    return result;
}

int main() {
    vector<variant<int, string>> list1 = {1, 2, "a", "b"};
    vector<variant<int, string>> list2 = {1, "a", "b", 0, 15};
    vector<variant<int, string>> list3 = {1, 2, "a", "b", "aasf", "1", "123", 123};

    for (int num : filterList(list1)) { cout << num << " "; } cout << endl;
    for (int num : filterList(list2)) { cout << num << " "; } cout << endl;
    for (int num : filterList(list3)) { cout << num << " "; } cout << endl;

    return 0;
}