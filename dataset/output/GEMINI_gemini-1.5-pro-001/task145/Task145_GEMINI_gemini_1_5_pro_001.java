public class Task145_GEMINI_gemini_1_5_pro_001 {
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

        int[] resultArray = new int[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; i++) {
            resultArray[i - startIndex] = arr[i];
        }
        return resultArray;
    }

    public static void main(String[] args) {
        int[] inputArray = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] result = maxSubarraySum(inputArray);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}