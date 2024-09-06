class MountainArray {
private:
    vector<int> arr;
    int calls;

public:
    MountainArray(vector<int> arr) : arr(arr), calls(0) {}

    int get(int index) {
        calls++;
        if (calls > 100) throw runtime_error("Too many calls");
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeakIndex(mountainArr);
        int index = binarySearch(mountainArr, target, 0, peak, true);
        if (index != -1) return index;
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

private:
    int findPeakIndex(MountainArray &arr) {
        int left = 0, right = arr.length() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int binarySearch(MountainArray &arr, int target, int left, int right, bool ascending) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int value = arr.get(mid);
            if (value == target) return mid;
            if (value < target) {
                if (ascending) left = mid + 1;
                else right = mid - 1;
            } else {
                if (ascending) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 3, 1};
    MountainArray mountainArr(vec);
    Solution sol;
    cout << sol.findInMountainArray(3, mountainArr) << endl;  // Output: 2
}