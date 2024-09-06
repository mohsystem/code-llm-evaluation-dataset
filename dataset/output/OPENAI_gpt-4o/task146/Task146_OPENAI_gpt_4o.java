// Program in Java
import java.util.*;

public class Task146_OPENAI_gpt_4o {
    public static int findMissingNumber(int[] arr, int n) {
        int total_sum = n * (n + 1) / 2;
        int array_sum = 0;
        for (int num : arr) {
            array_sum += num;
        }
        return total_sum - array_sum;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 4, 5, 6};
        int n = 6;
        System.out.println("Missing number is: " + findMissingNumber(arr, n));
    }
}