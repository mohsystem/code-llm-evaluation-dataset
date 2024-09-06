import java.util.Arrays;

public class Task171_OPENAI_gpt_4o {
    public static int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length);
    }

    private static int mergeSort(int[] nums, int start, int end) {
        if (end - start <= 1) {
            return 0;
        }
        
        int mid = (start + end) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid, end);
        int j = mid;
        
        for (int i = start; i < mid; i++) {
            while (j < end && nums[i] > 2L * nums[j]) {
                j++;
            }
            count += j - mid;
        }
        
        Arrays.sort(nums, start, end);
        return count;
    }
    
    public static void main(String[] args) {
        int[] nums1 = {1, 3, 2, 3, 1};
        System.out.println(reversePairs(nums1));  // Output: 2

        int[] nums2 = {2, 4, 3, 5, 1};
        System.out.println(reversePairs(nums2));  // Output: 3
    }
}