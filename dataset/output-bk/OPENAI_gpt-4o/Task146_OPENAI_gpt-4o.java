import java.util.*;

public class Main {
    public static int findMissingNumber(int[] array, int n) {
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : array) {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
    
    public static void main(String[] args) {
        int[] array = {1, 2, 4, 5, 6};  // Input your array here
        int n = array.length + 1;
        System.out.println("Missing number is: " + findMissingNumber(array, n));
    }
}