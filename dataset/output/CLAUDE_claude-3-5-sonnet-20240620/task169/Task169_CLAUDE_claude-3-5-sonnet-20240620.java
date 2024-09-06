
class Solution {
    private int[] count;
    private int[] indexes;
    private int[] temp;

    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();
        count = new int[nums.length];
        indexes = new int[nums.length];
        temp = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            indexes[i] = i;
        }

        mergeSort(nums, 0, nums.length - 1);

        for (int i : count) {
            result.add(i);
        }

        return result;
    }

    private void mergeSort(int[] nums, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }

    private void merge(int[] nums, int start, int mid, int end) {
        for (int i = start; i <= end; i++) {
            temp[i] = indexes[i];
        }

        int i = start;
        int j = mid + 1;
        int k = start;

        while (i <= mid && j <= end) {
            if (nums[temp[i]] <= nums[temp[j]]) {
                indexes[k] = temp[i];
                count[temp[i]] += j - (mid + 1);
                i++;
            } else {
                indexes[k] = temp[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            indexes[k] = temp[i];
            count[temp[i]] += end - mid;
            i++;
            k++;
        }
    }
}
