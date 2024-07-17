import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;

public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
        int target = 23;
        Instant start = Instant.now();
        int result = binarySearch(arr, target);
        Instant end = Instant.now();
        Duration timeElapsed = Duration.between(start, end);
        try (FileWriter writer = new FileWriter("execution_time.txt")) {
            writer.write("Execution time: " + timeElapsed.toMillis() + " milliseconds");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Element found at index " + result);
    }

    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
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
}