// C++
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int left = binarySearch(mountainArr, target, 0, peak, true);
        if (left != -1) return left;
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

    int binarySearch(MountainArray &mountainArr, int target, int left, int right, bool isAscending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) < target) {
                if (isAscending) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (isAscending) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};