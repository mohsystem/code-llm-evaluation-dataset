public class Main {
    public static int binaryArrayToNumber(int[] arr) {
        int result = 0;
        for (int i = 0; i < arr.length; i++) {
            result = result * 2 + arr[i];
        }
        return result;
    }
}