bool xorGame(vector<int>& nums) {
    int xor_all = 0;
    int count = 0;
    for (int num : nums) {
        xor_all ^= num;
        if ((num & 1) == 0) {
            count++;
        }
    }
    return xor_all == 0 || count % 2 == 1;
}