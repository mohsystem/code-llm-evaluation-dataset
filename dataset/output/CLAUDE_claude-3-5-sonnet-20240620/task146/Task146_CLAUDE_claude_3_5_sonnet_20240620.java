
import java.util.Arrays;

public class Task146_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int findMissingNumber(int[] arr) {
        int n = arr.length + 1;
        int expectedSum = n * (n + 1) / 2;
        int actualSum = Arrays.stream(arr).sum();
        return expectedSum - actualSum;
    }

    public static void main(String[] args) {
        int[] inputArray = {1, 2, 4, 6, 3, 7, 8};
        int missingNumber = findMissingNumber(inputArray);
        System.out.println("The missing number is: " + missingNumber);
    }
}
