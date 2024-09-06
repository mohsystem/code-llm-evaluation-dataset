#include <string>

class Solution {
public:
    bool solution(std::string str, std::string ending) {
      return str.ends_with(ending);
    }
};