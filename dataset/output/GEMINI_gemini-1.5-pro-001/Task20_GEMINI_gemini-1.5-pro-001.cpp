#include <cmath>
#include <string>

class DigPow
{
public:
    static long digPow(int n, int p){
      std::string num = std::to_string(n);
      long sum = 0;
      for (std::size_t i = 0; i < num.length(); i++, p++){
        sum += std::pow(num[i] - '0', p);
      }
      return (sum % n == 0) ? sum / n : -1;
    }
};