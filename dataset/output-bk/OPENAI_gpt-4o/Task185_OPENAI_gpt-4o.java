public class Main {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] A = nums1, B = nums2;
        if (A.length > B.length) {
            int[] temp = A; A = B; B = temp;
        }
        
        int m = A.length, n = B.length;
        int half = (m + n + 1) / 2, l = 0, r = m;
        
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;
            
            int Aleft = (i == 0) ? Integer.MIN_VALUE : A[i - 1];
            int Aright = (i == m) ? Integer.MAX_VALUE : A[i];
            int Bleft = (j == 0) ? Integer.MIN_VALUE : B[j - 1];
            int Bright = (j == n) ? Integer.MAX_VALUE : B[j];
            
            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) % 2 == 1) return Math.max(Aleft, Bleft);
                return (Math.max(Aleft, Bleft) + Math.min(Aright, Bright)) / 2.0;
            }
            if (Aleft > Bright) r = i - 1;
            else l = i + 1;
        }
        return 0.0;
    }
    public static void main(String[] args) {
        int[] nums1 = {1, 3};
        int[] nums2 = {2};
        System.out.println(findMedianSortedArrays(nums1, nums2));
    }
}