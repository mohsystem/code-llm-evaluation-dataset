bool xorGame(vector<int>& nums) {
    int xor_all = 0;
    for (int num : nums) {
        xor_all ^= num;
    }
    if (xor_all == 0) {
        return true;
    }
    int count = 0;
    for (int num : nums) {
        if (num % 2 == 0) {
            count++;
        }
    }
    return count % 2 == 0;
}