#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string oddOrEven(vector<int> arr) {
      int sum = 0;
      for(int i : arr) {
        sum += i;
      }
      return (sum % 2 == 0) ? "even" : "odd";
    }
};