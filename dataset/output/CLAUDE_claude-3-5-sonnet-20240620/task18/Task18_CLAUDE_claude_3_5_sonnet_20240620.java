
import java.util.Arrays;

public class Task18_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int convertBinaryArrayToInt(int[] binary) {
        return Integer.parseInt(Arrays.stream(binary)
                                      .mapToObj(String::valueOf)
                                      .reduce("", (a, b) -> a + b), 2);
    }

    public static void main(String[] args) {
        int[][] testCases = {
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 0, 1, 1}
        };

        for (int[] testCase : testCases) {
            System.out.println("Testing: " + Arrays.toString(testCase) + 
                               " ==> " + convertBinaryArrayToInt(testCase));
        }
    }
}
