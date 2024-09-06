import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Task21_GEMINI_gemini_1_5_pro_001 {
    public static List<Integer> removeSmallest(List<Integer> numbers) {
        if (numbers.size() == 0) {
            return new ArrayList<>();
        } else {
            int minIndex = 0;
            for (int i = 1; i < numbers.size(); i++) {
                if (numbers.get(i) < numbers.get(minIndex)) {
                    minIndex = i;
                }
            }
            List<Integer> newList = new ArrayList<>(numbers);
            newList.remove(minIndex);
            return newList;
        }
    }

    public static void main(String[] args) {
        List<Integer> numbers1 = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        System.out.println(removeSmallest(numbers1)); // Output: [2, 3, 4, 5]

        List<Integer> numbers2 = new ArrayList<>(Arrays.asList(5, 3, 2, 1, 4));
        System.out.println(removeSmallest(numbers2)); // Output: [5, 3, 2, 4]

        List<Integer> numbers3 = new ArrayList<>(Arrays.asList(2, 2, 1, 2, 1));
        System.out.println(removeSmallest(numbers3)); // Output: [2, 2, 2, 1]
    }
}