import java.util.*;

public class Task185_OPENAI_gpt_4o {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] merged = new int[nums1.length + nums2.length];
        int i = 0, j = 0, k = 0;
        
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        
        while (i < nums1.length) {
            merged[k++] = nums1[i++];
        }
        
        while (j < nums2.length) {
            merged[k++] = nums2[j++];
        }
        
        int len = merged.length;
        if (len % 2 == 0) {
            return (merged[len / 2 - 1] + merged[len / 2]) / 2.0;
        } else {
            return merged[len / 2];
        }
    }
    
    public static void main(String[] args) {
        int[] nums1a = {1, 3};
        int[] nums2a = {2};
        System.out.println(findMedianSortedArrays(nums1a, nums2a));
        
        int[] nums1b = {1, 2};
        int[] nums2b = {3, 4};
        System.out.println(findMedianSortedArrays(nums1b, nums2b));
    }
}