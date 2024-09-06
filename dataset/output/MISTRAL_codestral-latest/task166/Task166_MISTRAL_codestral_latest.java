import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class Task166_MISTRAL_codestral_latest {
    public static List<Integer> posNegSort(List<Integer> arr) {
        List<Integer> pos = new ArrayList<>();
        for (int num : arr) {
            if (num > 0) {
                pos.add(num);
            }
        }
        pos.sort(Integer::compare);
        int pos_i = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) > 0) {
                arr.set(i, pos.get(pos_i));
                pos_i += 1;
            }
        }
        return arr;
    }
}