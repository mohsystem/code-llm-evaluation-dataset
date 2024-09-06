import java.util.*;

public class Task21_OPENAI_gpt_4o {
    public static List<Integer> removeSmallest(List<Integer> numbers) {
        if (numbers.isEmpty()) return numbers;
        List<Integer> result = new ArrayList<>(numbers);
        int minIndex = numbers.indexOf(Collections.min(numbers));
        result.remove(minIndex);
        return result;
    }

    public static void main(String[] args) {
        System.out.println(removeSmallest(Arrays.asList(1, 2, 3, 4, 5)));
        System.out.println(removeSmallest(Arrays.asList(5, 3, 2, 1, 4)));
        System.out.println(removeSmallest(Arrays.asList(2, 2, 1, 2, 1)));
    }
}