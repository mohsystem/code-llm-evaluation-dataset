// Java code
public class Task170_MISTRAL_codestral_latest {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] prefixSum = new long[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return countWhileMergeSort(prefixSum, 0, prefixSum.length - 1, lower, upper);
    }

    private int countWhileMergeSort(long[] prefixSum, int start, int end, int lower, int upper) {
        if (end <= start) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = countWhileMergeSort(prefixSum, start, mid, lower, upper) + countWhileMergeSort(prefixSum, mid + 1, end, lower, upper);
        int j = mid + 1, k = mid + 1, lowerBound = mid + 1, upperBound = mid + 1;
        long[] cache = new long[end - start + 1];
        int idx = 0;
        for (int i = start; i <= mid; i++) {
            while (j <= end && prefixSum[j] - prefixSum[i] < lower) {
                j++;
            }
            while (k <= end && prefixSum[k] - prefixSum[i] <= upper) {
                k++;
            }
            count += k - j;
            while (lowerBound <= end && prefixSum[lowerBound] <= prefixSum[i]) {
                lowerBound++;
            }
            while (upperBound <= end && prefixSum[upperBound] < prefixSum[i]) {
                upperBound++;
            }
            count -= upperBound - lowerBound;
            while (start + idx <= mid && prefixSum[start + idx] <= prefixSum[i]) {
                cache[idx++] = prefixSum[start + idx];
            }
        }
        System.arraycopy(prefixSum, start + idx, cache, idx, mid - start + 1 - idx);
        System.arraycopy(cache, 0, prefixSum, start, mid - start + 1);
        return count;
    }
}