import java.util.*;

public class Task166_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int[] posNegSort(int[] arr) {
        List<Integer> pos = new ArrayList<>();
        for (int x : arr) {
            if (x > 0) {
                pos.add(x);
            }
        }
        Collections.sort(pos);
        int pos_index = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                arr[i] = pos.get(pos_index);
                pos_index++;
            }
        }
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = {6, 3, -2, 5, -8, 2, -2};
        arr = posNegSort(arr);
        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}