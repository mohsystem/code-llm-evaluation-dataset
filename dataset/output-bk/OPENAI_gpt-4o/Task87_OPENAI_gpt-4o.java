import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

class BinarySearch {
    public static int binarySearch(int[] arr, int x) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            // Check if x is present at mid
            if (arr[m] == x)
                return m;

            // If x greater, ignore left half
            if (arr[m] < x)
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
        // if we reach here, then element was not present
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int x = 10;

        long startTime = System.nanoTime();
        int result = binarySearch(arr, x);
        long endTime = System.nanoTime();

        long duration = endTime - startTime;

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("execution_time.txt"))) {
            writer.write("Execution time in nanoseconds: " + duration);
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index " + result);
    }
}