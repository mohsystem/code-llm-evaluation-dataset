#include <string>
#include <vector>

using namespace std;

string oddOrEven(vector<int> array) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i];
    }
    if (sum % 2 == 0) {
        return "even";
    } else {
        return "odd";
    }
}