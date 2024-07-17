import java.util.*;

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        List<Integer> sortedArr = new ArrayList<>();
        Integer[] counts = new Integer[n];

        for (int i = n - 1; i >= 0; i--) {
            int index = findIndex(sortedArr, nums[i]);
            counts[i] = index;
            sortedArr.add(index, nums[i]);
        }

        return Arrays.asList(counts);
    }

    private int findIndex(List<Integer> sortedArr, int target) {
        int left = 0;
        int right = sortedArr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sortedArr.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
}