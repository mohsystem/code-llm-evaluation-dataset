import java.util.Arrays;

public class Task166_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(posNegSort(new int[]{6, 3, -2, 5, -8, 2, -2})));  // [2, 3, -2, 5, -8, 6, -2]
        System.out.println(Arrays.toString(posNegSort(new int[]{6, 5, 4, -1, 3, 2, -1, 1})));  // [1, 2, 3, -1, 4, 5, -1, 6]
        System.out.println(Arrays.toString(posNegSort(new int[]{-5, -5, -5, -5, 7, -5})));  // [-5, -5, -5, -5, 7, -5]
        System.out.println(Arrays.toString(posNegSort(new int[]{})));  // []
    }
    
    public static int[] posNegSort(int[] lst) {
        int[] pos_nums = Arrays.stream(lst).filter(x -> x > 0).sorted().toArray();
        int pos_index = 0;
        int[] result = new int[lst.length];
        
        for (int i = 0; i < lst.length; i++) {
            if (lst[i] > 0) {
                result[i] = pos_nums[pos_index++];
            } else {
                result[i] = lst[i];
            }
        }
        
        return result;
    }
}