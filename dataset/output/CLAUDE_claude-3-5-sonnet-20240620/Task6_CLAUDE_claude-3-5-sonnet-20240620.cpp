
#include <iostream>
#include <vector>

class Kata {
public:
    static double findUniq(const std::vector<double> &arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        if (arr[1] != arr[0] && arr[1] != arr[2]) return arr[1];
        
        for (size_t i = 2; i < arr.size(); i++) {
            if (arr[i] != arr[0]) return arr[i];
        }
        
        return arr[0];
    }
};

int main() {
    std::cout << Kata::findUniq({1, 1, 1, 2, 1, 1}) << std::endl;
    std::cout << Kata::findUniq({0, 0, 0.55, 0, 0}) << std::endl;
    return 0;
}
