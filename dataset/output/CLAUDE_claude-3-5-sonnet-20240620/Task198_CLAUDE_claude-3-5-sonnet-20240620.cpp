
#include <iostream>
#include <vector>
#include <random>

int rand7() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 7);
    return dis(gen);
}

int rand10() {
    while (true) {
        int result = (rand7() - 1) * 7 + (rand7() - 1);
        if (result < 40) {
            return result % 10 + 1;
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of times to call rand10(): ";
    std::cin >> n;
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(rand10());
    }
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << result[i];
        if (i < n - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
    return 0;
}
