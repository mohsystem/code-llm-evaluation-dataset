import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int[] arr = {6, 3, -2, 5, -8, 2, -2};
        System.out.println(posNegSort(arr));
    }

    public static List<Integer> posNegSort(int[] arr) {
        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        for (int num : arr) {
            if (num > 0) {
                pos.add(num);
            } else {
                neg.add(num);
            }
        }

        Collections.sort(pos);

        for (int num : arr) {
            if (num > 0) {
                result.add(pos.remove(0));
            } else {
                result.add(num);
            }
        }

        return result;
    }
}