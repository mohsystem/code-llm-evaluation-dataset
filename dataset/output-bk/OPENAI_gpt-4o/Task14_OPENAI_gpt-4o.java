import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        int[] arr = {20, 10, -80, 10, 10, 15, 35};
        System.out.println(findEqualIndex(arr));
    }

    public static int findEqualIndex(int[] arr) {
        int totalSum = Arrays.stream(arr).sum();
        int leftSum = 0;

        for (int i = 0; i < arr.length; i++) {
            if (leftSum == totalSum - leftSum - arr[i]) {
                return i;
            }
            leftSum += arr[i];
        }
        return -1;
    }
}