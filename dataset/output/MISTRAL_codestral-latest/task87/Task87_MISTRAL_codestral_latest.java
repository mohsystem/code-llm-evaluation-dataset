import java.io.FileWriter;
import java.io.IOException;

public class Task87_MISTRAL_codestral_latest {
    int binarySearch(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }

    public static void main(String args[]) throws IOException {
        Task87_MISTRAL_codestral_latest ob = new Task87_MISTRAL_codestral_latest();
        int arr[] = {1, 3, 4, 10, 12, 90};
        int n = arr.length;
        int x = 10;
        long startTime = System.nanoTime();
        int result = ob.binarySearch(arr, 0, n - 1, x);
        long endTime = System.nanoTime();
        long executionTime = endTime - startTime;
        FileWriter myWriter = new FileWriter("execution_time.txt");
        myWriter.write(String.valueOf(executionTime));
        myWriter.close();
    }
}