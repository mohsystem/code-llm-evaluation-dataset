#include <vector>

bool xorGame(std::vector<int>& nums) {
    int xor = 0;
    for (int num : nums) {
        xor ^= num;
    }

    if (xor == 0) {
        return false;
    } else if (nums.size() % 2 == 0) {
        return false;
    } else {
        return true;
    }
}