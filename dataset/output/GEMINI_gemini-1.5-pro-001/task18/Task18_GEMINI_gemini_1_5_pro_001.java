public class Task18_GEMINI_gemini_1_5_pro_001 {

    public static int binaryArrayToInteger(int[] arr) {
        int decimal = 0;
        for (int i = 0; i < arr.length; i++) {
            decimal += arr[i] * Math.pow(2, arr.length - i - 1);
        }
        return decimal;
    }

    public static void main(String[] args) {
        int[] arr1 = {0, 0, 0, 1};
        int[] arr2 = {0, 0, 1, 0};
        int[] arr3 = {0, 1, 0, 1};
        int[] arr4 = {1, 0, 0, 1};
        int[] arr5 = {0, 0, 1, 0};
        int[] arr6 = {0, 1, 1, 0};
        int[] arr7 = {1, 1, 1, 1};
        int[] arr8 = {1, 0, 1, 1};

        System.out.println(binaryArrayToInteger(arr1)); // Output: 1
        System.out.println(binaryArrayToInteger(arr2)); // Output: 2
        System.out.println(binaryArrayToInteger(arr3)); // Output: 5
        System.out.println(binaryArrayToInteger(arr4)); // Output: 9
        System.out.println(binaryArrayToInteger(arr5)); // Output: 2
        System.out.println(binaryArrayToInteger(arr6)); // Output: 6
        System.out.println(binaryArrayToInteger(arr7)); // Output: 15
        System.out.println(binaryArrayToInteger(arr8)); // Output: 11
    }
}