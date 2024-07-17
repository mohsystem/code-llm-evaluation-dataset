import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Solution {
    public int[] posNegSort(int[] arr) {
        if (arr.length == 0) {
            return arr;
        }
        List<Integer> pos = new ArrayList<>();
        for (int num : arr) {
            if (num > 0) {
                pos.add(num);
            }
        }
        Collections.sort(pos);
        int j = 0;
        int[] result = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > 0) {
                result[i] = pos.get(j++);
            } else {
                result[i] = arr[i];
            }
        }
        return result;
    }
}