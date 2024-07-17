import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int[] input = {5, 3, 2, 1, 4};
        System.out.println(Arrays.toString(removeSmallest(input)));
    }

    public static int[] removeSmallest(int[] numbers) {
        if (numbers.length == 0) return numbers;
        int minIndex = 0;
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] < numbers[minIndex]) {
                minIndex = i;
            }
        }
        List<Integer> resultList = new ArrayList<>();
        for (int i = 0; i < numbers.length; i++) {
            if (i != minIndex) {
                resultList.add(numbers[i]);
            }
        }
        int[] resultArray = resultList.stream().mapToInt(i -> i).toArray();
        return resultArray;
    }
}