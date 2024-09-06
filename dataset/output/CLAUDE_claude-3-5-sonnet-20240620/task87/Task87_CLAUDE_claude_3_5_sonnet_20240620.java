
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Task87_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int target = 13;

        long startTime = System.nanoTime();
        int result = binarySearch(arr, target);
        long endTime = System.nanoTime();

        double executionTime = (endTime - startTime) / 1e9; // Convert to seconds

        try {
            Path tempFile = Files.createTempFile("execution_time", ".txt");
            try (FileWriter writer = new FileWriter(tempFile.toFile())) {
                writer.write(String.format("Execution time: %.6f seconds", executionTime));
            }
            System.out.println("Execution time written to: " + tempFile);
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Result: " + result);
    }
}
