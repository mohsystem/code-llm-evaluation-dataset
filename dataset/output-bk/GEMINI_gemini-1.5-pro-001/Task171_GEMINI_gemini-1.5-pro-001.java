class Solution {
    public int reversePairs(int[] nums) {
        int n = nums.length;
        if (n <= 1) {
            return 0;
        }
        int mid = n / 2;
        int[] left = Arrays.copyOfRange(nums, 0, mid);
        int[] right = Arrays.copyOfRange(nums, mid, n);
        return reversePairs(left) + reversePairs(right) + mergeAndCount(left, right);
    }

    private int mergeAndCount(int[] left, int[] right) {
        int n1 = left.length;
        int n2 = right.length;
        int[] merged = new int[n1 + n2];
        int i = 0;
        int j = 0;
        int k = 0;
        int count = 0;
        while (i < n1 && j < n2) {
            if (left[i] > 2 * right[j]) {
                count += n1 - i;
                j++;
            } else {
                i++;
            }
        }
        while (i < n1) {
            merged[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            merged[k] = right[j];
            j++;
            k++;
        }
        return count;
    }
}