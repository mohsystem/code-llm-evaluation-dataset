
import java.util.Arrays;

public class BinaryArrayToNumber {
    public static int convertBinaryArrayToInt(int[] binary) {
        return Arrays.stream(binary).reduce((result, bit) -> result * 2 + bit).getAsInt();
    }

    public static void main(String[] args) {
        System.out.println(convertBinaryArrayToInt(new int[]{0, 0, 0, 1})); // 1
        System.out.println(convertBinaryArrayToInt(new int[]{0, 0, 1, 0})); // 2
        System.out.println(convertBinaryArrayToInt(new int[]{0, 1, 0, 1})); // 5
        System.out.println(convertBinaryArrayToInt(new int[]{1, 0, 0, 1})); // 9
        System.out.println(convertBinaryArrayToInt(new int[]{0, 1, 1, 0})); // 6
        System.out.println(convertBinaryArrayToInt(new int[]{1, 1, 1, 1})); // 15
        System.out.println(convertBinaryArrayToInt(new int[]{1, 0, 1, 1})); // 11
    }
}
