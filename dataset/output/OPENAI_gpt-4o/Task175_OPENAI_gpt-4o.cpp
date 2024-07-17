class MountainArray {
public:
    virtual int get(int index) const = 0;
    virtual int length() const = 0;
};

class Solution {
public:
    int findInMountainArray(int target, const MountainArray &mountainArr) {
        int peak = peakIndexInMountainArray(mountainArr);
        int result = binarySearch(mountainArr, target, 0, peak, true);
        if (result != -1) {
            return result;
        }
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

private:
    int peakIndexInMountainArray(const MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(const MountainArray &mountainArr, int target, int left, int right, bool asc) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            }
            if (asc) {
                if (val < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (val > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};