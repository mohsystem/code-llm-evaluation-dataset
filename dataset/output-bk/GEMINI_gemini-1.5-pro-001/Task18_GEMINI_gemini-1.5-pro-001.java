public class BinaryArrayToInteger {
    public static void main(String[] args) {
        int[] binaryArray1 = {0, 0, 0, 1};
        int[] binaryArray2 = {0, 0, 1, 0};
        int[] binaryArray3 = {0, 1, 0, 1};
        int[] binaryArray4 = {1, 0, 0, 1};
        int[] binaryArray5 = {0, 0, 1, 0};
        int[] binaryArray6 = {0, 1, 1, 0};
        int[] binaryArray7 = {1, 1, 1, 1};
        int[] binaryArray8 = {1, 0, 1, 1};

        System.out.println(binaryArrayToInteger(binaryArray1)); // Output: 1
        System.out.println(binaryArrayToInteger(binaryArray2)); // Output: 2
        System.out.println(binaryArrayToInteger(binaryArray3)); // Output: 5
        System.out.println(binaryArrayToInteger(binaryArray4)); // Output: 9
        System.out.println(binaryArrayToInteger(binaryArray5)); // Output: 2
        System.out.println(binaryArrayToInteger(binaryArray6)); // Output: 6
        System.out.println(binaryArrayToInteger(binaryArray7)); // Output: 15
        System.out.println(binaryArrayToInteger(binaryArray8)); // Output: 11
    }

    public static int binaryArrayToInteger(int[] binaryArray) {
        int decimalValue = 0;
        int arrayLength = binaryArray.length;
        for (int i = 0; i < arrayLength; i++) {
            if (binaryArray[i] == 1) {
                decimalValue += Math.pow(2, arrayLength - 1 - i);
            }
        }
        return decimalValue;
    }
}