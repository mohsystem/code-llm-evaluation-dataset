class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums = new int[nums1.length + nums2.length];
        int i1 = 0, i2 = 0, i = 0;
        while (i1 < nums1.length && i2 < nums2.length) {
            if (nums1[i1] < nums2[i2]) {
                nums[i++] = nums1[i1++];
            } else {
                nums[i++] = nums2[i2++];
            }
        }
        while (i1 < nums1.length) {
            nums[i++] = nums1[i1++];
        }
        while (i2 < nums2.length) {
            nums[i++] = nums2[i2++];
        }

        int n = nums.length;
        if (n % 2 == 0) {
            return (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
        } else {
            return nums[n / 2];
        }
    }
}