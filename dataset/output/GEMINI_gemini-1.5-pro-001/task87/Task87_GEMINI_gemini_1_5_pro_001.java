import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;
import java.util.Random;

public class Task87_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        // Generate a sorted array of 1 million random integers
        int[] array = generateSortedArray(1000000);

        // Choose a random target value from the array
        Random random = new Random();
        int target = array[random.nextInt(array.length)];

        // Start the timer
        long startTime = System.nanoTime();

        // Perform binary search
        int index = binarySearch(array, target);

        // Stop the timer
        long endTime = System.nanoTime();

        // Calculate execution time in milliseconds
        double executionTime = (endTime - startTime) / 1000000.0;

        // Store execution time in a temporary file
        try {
            String output = "Binary search execution time: " + executionTime + " ms";
            Files.writeString(Path.of("temp.txt"), output, StandardOpenOption.CREATE);
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }

    // Performs binary search on a sorted array
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == target) {
                return mid;
            } else if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    // Generates a sorted array of random integers
    public static int[] generateSortedArray(int size) {
        Random random = new Random();
        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt();
        }

        Arrays.sort(array);
        return array;
    }
}