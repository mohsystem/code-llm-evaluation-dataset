import java.util.List;
import java.util.Arrays;

public class Task18_OPENAI_gpt_4o {
    public static int binaryArrayToInt(List<Integer> arr) {
        int result = 0;
        for (int bit : arr) {
            result = (result << 1) | bit;
        }
        return result;
    }

    public static void main(String[] args) {
        List<List<Integer>> testCases = Arrays.asList(
            Arrays.asList(0, 0, 0, 1),
            Arrays.asList(0, 0, 1, 0),
            Arrays.asList(0, 1, 0, 1),
            Arrays.asList(1, 0, 0, 1),
            Arrays.asList(0, 0, 1, 0),
            Arrays.asList(0, 1, 1, 0),
            Arrays.asList(1, 1, 1, 1),
            Arrays.asList(1, 0, 1, 1)
        );

        for (List<Integer> testCase : testCases) {
            System.out.println("Testing: " + testCase + " ==> " + binaryArrayToInt(testCase));
        }
    }
}