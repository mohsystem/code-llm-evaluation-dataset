
import java.util.Arrays;
import java.util.Scanner;

public class Task147_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();
        System.out.println("The " + k + "th largest element is: " + findKthLargest(nums, k));
        scanner.close();
    }
}
