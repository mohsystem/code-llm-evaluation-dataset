#include <iostream>
#include <random>
using namespace std;
class Solution {
public:
    int rand10() {
        while (true) {
            int row = rand7();
            int col = rand7();
            int idx = col + (row - 1) * 7;
            if (idx <= 40) {
                return 1 + (idx - 1) % 10;
            }
        }
    }
private:
    int rand7() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 7);
        return distrib(gen);
    }
};