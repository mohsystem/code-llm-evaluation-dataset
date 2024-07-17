import java.util.Arrays;
import java.util.List;

public class ConvertBinaryArrayToInt {
    public static void main(String[] args) {
        List<int[]> testCases = Arrays.asList(
            new int[]{0, 0, 0, 1},
            new int[]{0, 0, 1, 0},
            new int[]{0, 1, 0, 1},
            new int[]{1, 0, 0, 1},
            new int[]{0, 0, 1, 0},
            new int[]{0, 1, 1, 0},
            new int[]{1, 1, 1, 1},
            new int[]{1, 0, 1, 1}
        );

        for (int[] testCase : testCases) {
            System.out.println(convertBinaryArrayToInt(testCase));
        }
    }

    public static int convertBinaryArrayToInt(int[] binaryArray) {
        int result = 0;
        for (int i = 0; i < binaryArray.length; i++) {
            result = result * 2 + binaryArray[i];
        }
        return result;
    }
}