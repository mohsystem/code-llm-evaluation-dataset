#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (true) {
        int num = (rand7() - 1) * 7 + rand7();
        if (num <= 40) {
            return (num - 1) % 10 + 1;
        }
    }
}

int main() {
    srand((unsigned)time(0));
    int n;
    std::cin >> n;
    std::vector<int> results;
    for (int i = 0; i < n; i++) {
        results.push_back(rand10());
    }
    for (int num : results) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}