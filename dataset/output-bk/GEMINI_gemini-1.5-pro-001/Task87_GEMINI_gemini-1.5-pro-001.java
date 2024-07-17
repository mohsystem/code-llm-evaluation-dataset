import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;
import java.util.Random;

public class BinarySearchTimer {

    public static void main(String[] args) {
        // Generate a sorted array of random integers
        int[] array = generateSortedArray(1000000);

        // Value to search for
        int searchValue = 50000;

        // Measure execution time
        long startTime = System.nanoTime();
        int index = binarySearch(array, searchValue);
        long endTime = System.nanoTime();

        // Calculate execution time in milliseconds
        double executionTimeMs = (endTime - startTime) / 1_000_000.0;

        // Write execution time to temporary file
        try {
            String tempFileContent = "Binary search execution time: " + executionTimeMs + " ms
";
            Path tempFile = Files.createTempFile("binary-search-timer-", ".txt");
            Files.writeString(tempFile, tempFileContent, StandardOpenOption.CREATE);
            System.out.println("Execution time written to: " + tempFile.toAbsolutePath());
        } catch (IOException e) {
            System.err.println("Error writing to temporary file: " + e.getMessage());
        }

        // Print result (optional)
        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found in the array.");
        }
    }

    // Binary search implementation
    private static int binarySearch(int[] array, int value) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == value) {
                return mid;
            } else if (array[mid] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    // Helper function to generate a sorted array of random integers
    private static int[] generateSortedArray(int size) {
        Random random = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(size * 10); // Adjust range as needed
        }
        Arrays.sort(array);
        return array;
    }
}