class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(vec.begin(), vec.end(), make_pair(nums[i], -1));
            res[vec[i].second] = it - vec.begin();
        }
        return res;
    }
};