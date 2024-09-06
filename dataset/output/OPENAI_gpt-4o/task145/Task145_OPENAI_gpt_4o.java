import java.util.Scanner;

public class Task145_OPENAI_gpt_4o {
    public static void main(String[] args) {
        int[] arr = {1, -3, 2, 1, -1};
        System.out.println("Max contiguous subarray sum is: " + maxSubArraySum(arr));
    }

    public static int maxSubArraySum(int[] arr) {
        int maxCurrent = arr[0];
        int maxGlobal = arr[0];

        for (int i = 1; i < arr.length; i++) {
            maxCurrent = Math.max(arr[i], maxCurrent + arr[i]);
            if (maxCurrent > maxGlobal) {
                maxGlobal = maxCurrent;
            }
        }
        return maxGlobal;
    }
}