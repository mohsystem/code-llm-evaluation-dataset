#include <iostream>
#include <random>
using namespace std;
class Solution {
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7(); // Generate a number between 1 and 49
            if (num <= 40) {
                return (num - 1) % 10 + 1; // Map to 1-10
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