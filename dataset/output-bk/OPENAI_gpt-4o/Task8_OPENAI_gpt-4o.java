import java.util.*;

public class Main {
    public static char findMissingLetter(char[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i + 1] != array[i] + 1) {
                return (char) (array[i] + 1);
            }
        }
        throw new IllegalArgumentException("No missing letter detected.");
    }

    public static void main(String[] args) {
        char[] array1 = {'a', 'b', 'c', 'd', 'f'};
        char[] array2 = {'O', 'Q', 'R', 'S'};

        System.out.println(findMissingLetter(array1)); // Output: e
        System.out.println(findMissingLetter(array2)); // Output: P
    }
}