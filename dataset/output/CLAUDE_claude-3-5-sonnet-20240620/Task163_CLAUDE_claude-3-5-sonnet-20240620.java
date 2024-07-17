
import java.util.Arrays;

public class ConsecutiveRun {
    public static int longestRun(int[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        
        int maxRun = 1;
        int currentRun = 1;
        
        for (int i = 1; i < arr.length; i++) {
            if (Math.abs(arr[i] - arr[i-1]) == 1) {
                currentRun++;
                maxRun = Math.max(maxRun, currentRun);
            } else {
                currentRun = 1;
            }
        }
        
        return maxRun;
    }

    public static void main(String[] args) {
        System.out.println(longestRun(new int[]{1, 2, 3, 5, 6, 7, 8, 9}));  // 5
        System.out.println(longestRun(new int[]{1, 2, 3, 10, 11, 15}));  // 3
        System.out.println(longestRun(new int[]{5, 4, 2, 1}));  // 2
        System.out.println(longestRun(new int[]{3, 5, 7, 10, 15}));  // 1
    }
}
