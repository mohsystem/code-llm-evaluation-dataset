class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> enumVec;
        for (int i = 0; i < nums.size(); i++) {
            enumVec.push_back({nums[i], i});
        }
        sort(enumVec.begin(), enumVec.end(), greater<pair<int, int>>());
        vector<int> counts(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            counts[enumVec[i].second] = i;
        }
        return counts;
    }
};