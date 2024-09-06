import java.util.ArrayList;
import java.util.Collections;
class Solution {
    public int[] posNegSort(int[] arr) {
      if (arr.length == 0) {
        return arr;
      }
      ArrayList<Integer> posList = new ArrayList<Integer>();
      for (int i = 0; i < arr.length; i++) {
        if (arr[i] > 0) {
          posList.add(arr[i]);
        }
      }
      Collections.sort(posList);
      int j = 0;
      for (int i = 0; i < arr.length; i++) {
        if (arr[i] > 0) {
          arr[i] = posList.get(j++);
        }
      }
      return arr;
    }
}