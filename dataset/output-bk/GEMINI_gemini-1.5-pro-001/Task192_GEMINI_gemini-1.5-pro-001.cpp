class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        return xor == 0 || nums.size() % 2 == 0;
    }
};