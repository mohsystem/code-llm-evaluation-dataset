public class Main {
    public static void main(String[] args) {
        int[] arr1 = {0, 0, 0, 1};
        int[] arr2 = {0, 0, 1, 0};
        int[] arr3 = {0, 1, 0, 1};
        int[] arr4 = {1, 0, 0, 1};
        int[] arr5 = {0, 0, 1, 0};
        int[] arr6 = {0, 1, 1, 0};
        int[] arr7 = {1, 1, 1, 1};
        int[] arr8 = {1, 0, 1, 1};

        System.out.println(binaryArrayToNumber(arr1));
        System.out.println(binaryArrayToNumber(arr2));
        System.out.println(binaryArrayToNumber(arr3));
        System.out.println(binaryArrayToNumber(arr4));
        System.out.println(binaryArrayToNumber(arr5));
        System.out.println(binaryArrayToNumber(arr6));
        System.out.println(binaryArrayToNumber(arr7));
        System.out.println(binaryArrayToNumber(arr8));
    }

    public static int binaryArrayToNumber(int[] arr) {
        int num = 0;
        for (int i = 0; i < arr.length; i++) {
            num += arr[i] * Math.pow(2, arr.length - i - 1);
        }
        return num;
    }
}