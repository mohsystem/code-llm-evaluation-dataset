public class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] sums = new long[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countWhileMergeSort(sums, 0, sums.length - 1, lower, upper);
    }

    private int countWhileMergeSort(long[] sums, int start, int end, int lower, int upper) {
        if (end <= start) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) + countWhileMergeSort(sums, mid + 1, end, lower, upper);
        int j = mid + 1, k = mid + 1;
        long[] cache = new long[end - start + 1];
        int idx = 0;
        for (int i = start; i <= mid; i++) {
            while (j <= end && sums[j] - sums[i] < lower) {
                j++;
            }
            while (k <= end && sums[k] - sums[i] <= upper) {
                k++;
            }
            count += k - j;
            while (idx < cache.length && sums[start + idx] <= sums[i]) {
                cache[idx++] = sums[start + idx];
            }
            cache[idx++] = sums[i];
        }
        System.arraycopy(cache, 0, sums, start, idx);
        return count;
    }
}