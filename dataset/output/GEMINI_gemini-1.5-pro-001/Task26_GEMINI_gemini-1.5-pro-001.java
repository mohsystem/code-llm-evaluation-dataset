import java.util.HashMap;

class Solution {
    public static int findOdd(int[] arr) {
        HashMap<Integer, Integer> counts = new HashMap<>();

        for (int num : arr) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        for (int num : counts.keySet()) {
            if (counts.get(num) % 2 != 0) {
                return num;
            }
        }
        return -1; 
    }

    public static void main(String[] args) {
        int[] arr1 = {7};
        int[] arr2 = {0};
        int[] arr3 = {1, 1, 2};
        int[] arr4 = {0, 1, 0, 1, 0};
        int[] arr5 = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};

        System.out.println(findOdd(arr1)); 
        System.out.println(findOdd(arr2)); 
        System.out.println(findOdd(arr3)); 
        System.out.println(findOdd(arr4)); 
        System.out.println(findOdd(arr5)); 
    }
}