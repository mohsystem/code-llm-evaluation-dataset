public class Task185_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] merged = new int[nums1.length + nums2.length];
        System.arraycopy(nums1, 0, merged, 0, nums1.length);
        System.arraycopy(nums2, 0, merged, nums1.length, nums2.length);
        Arrays.sort(merged);
        int length = merged.length;
        if (length % 2 == 0) {
            return (merged[length / 2 - 1] + merged[length / 2]) / 2.0;
        } else {
            return merged[length / 2];
        }
    }
}