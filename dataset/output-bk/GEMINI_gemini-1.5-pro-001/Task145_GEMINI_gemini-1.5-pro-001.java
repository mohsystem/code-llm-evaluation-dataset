public class MaxSubarray {
    public static int[] maxSubarraySum(int[] arr) {
        int maxSoFar = Integer.MIN_VALUE;
        int currentMax = 0;
        int startIndex = 0;
        int endIndex = 0;
        int j = 0;

        for (int i = 0; i < arr.length; i++) {
            currentMax += arr[i];

            if (currentMax > maxSoFar) {
                maxSoFar = currentMax;
                startIndex = j;
                endIndex = i;
            }

            if (currentMax < 0) {
                currentMax = 0;
                j = i + 1;
            }
        }

        // Extract the subarray with maximum sum
        int[] maxSubarray = new int[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            maxSubarray[i - startIndex] = arr[i];
        }
        return maxSubarray;
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] maxSubArray = maxSubarraySum(arr);
        System.out.print("Maximum contiguous subarray: [");
        for (int i = 0; i < maxSubArray.length; i++) {
            System.out.print(maxSubArray[i]);
            if (i < maxSubArray.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
}