
import java.io.*;
import java.util.Arrays;

public class BinarySearchWithTimer {
    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int target = 13;

        long startTime = System.nanoTime();
        int result = binarySearch(arr, target);
        long endTime = System.nanoTime();

        long executionTime = endTime - startTime;

        try {
            File tempFile = File.createTempFile("execution_time", ".txt");
            FileWriter writer = new FileWriter(tempFile);
            writer.write("Execution time: " + executionTime + " nanoseconds");
            writer.close();
            System.out.println("Execution time written to: " + tempFile.getAbsolutePath());
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found");
        }
    }

    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
}
