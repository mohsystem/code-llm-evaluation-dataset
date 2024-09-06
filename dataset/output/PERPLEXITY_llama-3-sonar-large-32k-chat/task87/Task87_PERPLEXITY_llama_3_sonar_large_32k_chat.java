import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;

public class Task87_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int binarySearch(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = new int[10000];
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(101);
        }
        Arrays.sort(arr);

        long startTime = System.nanoTime();
        int index = binarySearch(arr, 50);
        long endTime = System.nanoTime();

        try (FileWriter fw = new FileWriter("temp.txt")) {
            fw.write("Execution time: " + (endTime - startTime) / 1e9 + " seconds\n");
            if (index != -1) {
                fw.write("Target found at index " + index + "\n");
            } else {
                fw.write("Target not found\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}