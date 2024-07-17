import java.util.Arrays;

public class OutlierFinder {
    public static int findOutlier(int[] arr) {
        int oddCount = 0;
        int evenCount = 0;
        int oddNum = 0;
        int evenNum = 0;

        for (int i = 0; i < arr.length && (oddCount == 0 || evenCount == 0); i++) {
            if (arr[i] % 2 == 0) {
                evenCount++;
                evenNum = arr[i];
            } else {
                oddCount++;
                oddNum = arr[i];
            }
        }

        return oddCount == 1 ? oddNum : evenNum;
    }

    public static void main(String[] args) {
        int[] example1 = {2, 4, 0, 100, 4, 11, 2602, 36};
        int[] example2 = {160, 3, 1719, 19, 11, 13, -21};
        System.out.println(findOutlier(example1)); // Should print 11
        System.out.println(findOutlier(example2)); // Should print 160
    }
}