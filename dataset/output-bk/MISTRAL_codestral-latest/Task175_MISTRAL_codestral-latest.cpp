// C++
// The code below uses binary search to find the target in the mountain array.
// It first finds the peak of the mountain array, then performs binary search in the increasing and decreasing parts of the array.

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int res = binarySearch(mountainArr, target, 0, peak);
        if (res != -1) {
            return res;
        }
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

private:
    int findPeak(MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool ascending = true) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur = mountainArr.get(mid);
            if (cur == target) {
                return mid;
            } else if (cur < target) {
                if (ascending) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (ascending) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};