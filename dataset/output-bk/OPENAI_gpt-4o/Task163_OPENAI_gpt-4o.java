import java.util.*;

public class Main {
    public static int longestRun(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }

        int maxLength = 1;
        int currentLength = 1;

        // Check for increasing consecutive runs
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                currentLength += 1;
            } else {
                maxLength = Math.max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = Math.max(maxLength, currentLength);

        currentLength = 1;

        // Check for decreasing consecutive runs
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1] - 1) {
                currentLength += 1;
            } else {
                maxLength = Math.max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        maxLength = Math.max(maxLength, currentLength);

        return maxLength;
    }

    public static void main(String[] args) {
        System.out.println(longestRun(new int[]{1, 2, 3, 5, 6, 7, 8, 9})); // ➞ 5
        System.out.println(longestRun(new int[]{1, 2, 3, 10, 11, 15})); // ➞ 3
        System.out.println(longestRun(new int[]{5, 4, 2, 1})); // ➞ 2
        System.out.println(longestRun(new int[]{3, 5, 7, 10, 15})); // ➞ 1
    }
}