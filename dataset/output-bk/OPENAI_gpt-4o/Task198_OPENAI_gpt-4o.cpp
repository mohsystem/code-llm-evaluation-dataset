#include <iostream>
#include <vector>

int rand7() {
    return rand() % 7 + 1;
}

int rand10() {
    while (true) {
        int x = (rand7() - 1) * 7 + rand7();
        if (x <= 40) {
            return 1 + (x - 1) % 10;
        }
    }
}

int main() {
    srand(time(0));
    int n = 3;
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(rand10());
    }
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}