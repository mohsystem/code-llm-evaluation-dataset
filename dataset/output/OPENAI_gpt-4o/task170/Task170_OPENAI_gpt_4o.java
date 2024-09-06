public class Task170_OPENAI_gpt_4o {
    private int count;

    public int countRangeSum(int[] nums, int lower, int upper) {
        count = 0;
        long[] sums = new long[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        mergeSort(sums, 0, sums.length - 1, lower, upper);
        return count;
    }

    private void mergeSort(long[] sums, int lo, int hi, int lower, int upper) {
        if (lo >= hi) return;
        int mid = (lo + hi) / 2;
        mergeSort(sums, lo, mid, lower, upper);
        mergeSort(sums, mid + 1, hi, lower, upper);

        long[] cache = new long[hi - lo + 1];
        int i = lo, j = mid + 1, k = 0, m = mid + 1, n = mid + 1;
        while (i <= mid) {
            while (m <= hi && sums[m] - sums[i] < lower) m++;
            while (n <= hi && sums[n] - sums[i] <= upper) n++;
            count += n - m;
            while (j <= hi && sums[j] < sums[i]) cache[k++] = sums[j++];
            cache[k++] = sums[i++];
        }
        System.arraycopy(sums, lo, cache, k, mid - i + 1);
        System.arraycopy(cache, 0, sums, lo, hi - lo + 1);
    }

    public static void main(String[] args) {
        Task170_OPENAI_gpt_4o sol = new Task170_OPENAI_gpt_4o();
        int[] nums = {-2, 5, -1};
        int lower = -2, upper = 2;
        System.out.println(sol.countRangeSum(nums, lower, upper));  // Output: 3
    }
}