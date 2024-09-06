import java.util.HashMap;

public class Task26_OPENAI_gpt_4o {
    public static int findOddOccurrence(int[] arr) {
        int result = 0;
        for (int number : arr) {
            result ^= number;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(findOddOccurrence(new int[]{7}));
        System.out.println(findOddOccurrence(new int[]{0}));
        System.out.println(findOddOccurrence(new int[]{1, 1, 2}));
        System.out.println(findOddOccurrence(new int[]{0, 1, 0, 1, 0}));
        System.out.println(findOddOccurrence(new int[]{1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1}));
    }
}