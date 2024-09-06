#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSort(arr, count, 0, n - 1);

        return count;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& count, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }

    void merge(vector<pair<int, int>>& arr, vector<int>& count, int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        vector<pair<int, int>> temp(right - left + 1);
        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                count[arr[i].second] += j - (mid + 1);
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            count[arr[i].second] += j - (mid + 1);
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        for (int p = 0; p < k; p++) {
            arr[left + p] = temp[p];
        }
    }
};