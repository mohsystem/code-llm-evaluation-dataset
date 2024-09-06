
import java.util.Arrays;

public class Task9_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String oddOrEven(int[] array) {
        return Arrays.stream(array).sum() % 2 == 0 ? "even" : "odd";
    }

    public static void main(String[] args) {
        System.out.println(oddOrEven(new int[]{0}));  // Output: "even"
        System.out.println(oddOrEven(new int[]{0, 1, 4}));  // Output: "odd"
        System.out.println(oddOrEven(new int[]{0, -1, -5}));  // Output: "even"
    }
}
