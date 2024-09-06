import java.util.Arrays;

public class Task144_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        int[] arr1 = {1, 3, 5, 7};
        int[] arr2 = {2, 4, 6, 8};
        int[] merged = new int[arr1.length + arr2.length];
        System.arraycopy(arr1, 0, merged, 0, arr1.length);
        System.arraycopy(arr2, 0, merged, arr1.length, arr2.length);
        Arrays.sort(merged);
        for (int i : merged) {
            System.out.print(i + " ");
        }
    }
}