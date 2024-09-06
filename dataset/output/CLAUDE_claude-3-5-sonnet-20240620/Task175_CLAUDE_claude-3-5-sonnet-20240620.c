
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
struct MountainArray;
int get(struct MountainArray *, int index);
int length(struct MountainArray *);

int findInMountainArray(int target, struct MountainArray* mountainArr) {
    int length = length(mountainArr);
    
    // Find peak element
    int left = 0, right = length - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int peak = left;
    
    // Binary search in the left side
    left = 0;
    right = peak;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = get(mountainArr, mid);
        if (midVal == target) {
            return mid;
        } else if (midVal < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // Binary search in the right side
    left = peak;
    right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = get(mountainArr, mid);
        if (midVal == target) {
            return mid;
        } else if (midVal > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
