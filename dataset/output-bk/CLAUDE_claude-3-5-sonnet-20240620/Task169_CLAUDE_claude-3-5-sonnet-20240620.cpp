
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        vector<pair<int, int>> enum_nums;
        for (int i = 0; i < nums.size(); i++) {
            enum_nums.push_back({i, nums[i]});
        }
        merge_sort(enum_nums, counts, 0, nums.size() - 1);
        return counts;
    }
    
private:
    void merge_sort(vector<pair<int, int>>& enum_nums, vector<int>& counts, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        merge_sort(enum_nums, counts, left, mid);
        merge_sort(enum_nums, counts, mid + 1, right);
        merge(enum_nums, counts, left, mid, right);
    }
    
    void merge(vector<pair<int, int>>& enum_nums, vector<int>& counts, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (enum_nums[i].second <= enum_nums[j].second) {
                temp[k] = enum_nums[i];
                counts[enum_nums[i].first] += j - (mid + 1);
                i++;
            } else {
                temp[k] = enum_nums[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            temp[k] = enum_nums[i];
            counts[enum_nums[i].first] += right - mid;
            i++;
            k++;
        }
        while (j <= right) {
            temp[k] = enum_nums[j];
            j++;
            k++;
        }
        copy(temp.begin(), temp.end(), enum_nums.begin() + left);
    }
};
