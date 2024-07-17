import java.util.Arrays;

class Solution {
    public static void main(String[] args) {
        char[] arr1 = {'a', 'b', 'c', 'd', 'f'};
        char[] arr2 = {'O', 'Q', 'R', 'S'};

        System.out.println(findMissingLetter(arr1));
        System.out.println(findMissingLetter(arr2));
    }
    public static char findMissingLetter(char[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i] - array[i - 1] != 1) {
                return (char) (array[i] - 1);
            }
        }
        return ' ';
    }
}