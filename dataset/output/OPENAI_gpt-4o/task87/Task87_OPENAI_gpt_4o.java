import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.util.Arrays;

public class Task87_OPENAI_gpt_4o {
    public static int binarySearch(int[] arr, int x) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        int[] arr = { 2, 3, 4, 10, 40 };
        int x = 10;
        long startTime = System.nanoTime();
        int result = binarySearch(arr, x);
        long endTime = System.nanoTime();
        long executionTime = endTime - startTime;

        File tempFile = File.createTempFile("binary_search_execution_time", ".txt");
        try (FileWriter writer = new FileWriter(tempFile)) {
            writer.write("Execution time: " + executionTime + " nanoseconds");
        }
    }
}