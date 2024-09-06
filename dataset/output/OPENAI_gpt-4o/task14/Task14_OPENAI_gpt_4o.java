import java.util.Arrays;

public class Task14_OPENAI_gpt_4o {
    public static int findEvenIndex(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int leftSum = Arrays.stream(arr, 0, i).sum();
            int rightSum = Arrays.stream(arr, i + 1, arr.length).sum();
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(findEvenIndex(new int[]{1, 2, 3, 4, 3, 2, 1}));  // Output should be 3
        System.out.println(findEvenIndex(new int[]{1, 100, 50, -51, 1, 1}));  // Output should be 1
        System.out.println(findEvenIndex(new int[]{20, 10, -80, 10, 10, 15, 35}));  // Output should be 0
    }
}