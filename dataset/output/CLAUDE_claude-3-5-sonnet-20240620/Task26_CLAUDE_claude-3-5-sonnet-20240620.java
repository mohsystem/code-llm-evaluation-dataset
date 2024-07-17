
import java.util.HashMap;
import java.util.Map;

public class OddOccurrence {
    public static int findOddOccurrence(int[] arr) {
        Map<Integer, Integer> countMap = new HashMap<>();
        
        for (int num : arr) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() % 2 != 0) {
                return entry.getKey();
            }
        }
        
        return -1; // This line should never be reached given the problem constraints
    }

    public static void main(String[] args) {
        int[] arr1 = {7};
        int[] arr2 = {0};
        int[] arr3 = {1,1,2};
        int[] arr4 = {0,1,0,1,0};
        int[] arr5 = {1,2,2,3,3,3,4,3,3,3,2,2,1};

        System.out.println(findOddOccurrence(arr1));
        System.out.println(findOddOccurrence(arr2));
        System.out.println(findOddOccurrence(arr3));
        System.out.println(findOddOccurrence(arr4));
        System.out.println(findOddOccurrence(arr5));
    }
}
