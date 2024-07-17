import java.util.Arrays;
class Solution {
    public static void main(String[] args) {
        int[] input = {2,2,1,2,1};
        int[] output = removeSmallest(input);
        System.out.println(Arrays.toString(output));
    }

   public static int[] removeSmallest(int[] numbers) {
        if (numbers.length == 0) {
            return new int[0]; // Return an empty array if the input is empty
        }

        // Find the index of the smallest element
        int minIndex = 0;
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] < numbers[minIndex]) {
                minIndex = i;
            }
        }

        // Create a new array without the smallest element
        int[] result = new int[numbers.length - 1];
        int index = 0;
        for (int i = 0; i < numbers.length; i++) {
            if (i != minIndex) {
                result[index++] = numbers[i];
            }
        }

        return result;
    }
}