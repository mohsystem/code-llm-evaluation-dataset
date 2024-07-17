import java.util.*;
import java.util.stream.Collectors;

public class PosNegSort {

    public static List<Integer> posNegSort(List<Integer> arr) {
        List<Integer> posNumbers = arr.stream().filter(x -> x > 0).sorted().collect(Collectors.toList());
        int posIdx = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) > 0) {
                arr.set(i, posNumbers.get(posIdx++));
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        System.out.println(posNegSort(Arrays.asList(6, 3, -2, 5, -8, 2, -2)));  // ➞ [2, 3, -2, 5, -8, 6, -2]
        System.out.println(posNegSort(Arrays.asList(6, 5, 4, -1, 3, 2, -1, 1)));  // ➞ [1, 2, 3, -1, 4, 5, -1, 6]
        System.out.println(posNegSort(Arrays.asList(-5, -5, -5, -5, 7, -5)));  // ➞ [-5, -5, -5, -5, 7, -5]
        System.out.println(posNegSort(Arrays.asList()));  // ➞ []
    }
}