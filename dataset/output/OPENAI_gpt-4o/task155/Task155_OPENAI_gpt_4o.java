import java.util.ArrayList;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;

public class Task155_OPENAI_gpt_4o {
    public static void heapify(ArrayList<Integer> arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr.get(i) < arr.get(l))
            largest = l;

        if (r < n && arr.get(largest) < arr.get(r))
            largest = r;

        if (largest != i) {
            int swap = arr.get(i);
            arr.set(i, arr.get(largest));
            arr.set(largest, swap);
            heapify(arr, n, largest);
        }
    }

    public static void heapSort(ArrayList<Integer> arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr.get(0);
            arr.set(0, arr.get(i));
            arr.set(i, temp);
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(4);
        arr.add(10);
        arr.add(3);
        arr.add(5);
        arr.add(1);
        heapSort(arr);
        System.out.println("Sorted array is: " + arr);
    }
}