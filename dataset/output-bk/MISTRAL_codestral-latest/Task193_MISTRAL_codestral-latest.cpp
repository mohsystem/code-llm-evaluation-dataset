#include <vector>

bool xorGame(std::vector<int>& nums) {
    int xor = 0;
    for (int num : nums) {
        xor ^= num;
    }
    return nums.size() % 2 == 1 && xor != 0;
}