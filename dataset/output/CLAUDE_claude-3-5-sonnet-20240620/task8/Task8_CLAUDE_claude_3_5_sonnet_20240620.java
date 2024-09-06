
public class Task8_CLAUDE_claude_3_5_sonnet_20240620 {
    public static char findMissingLetter(char[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i + 1] - array[i] > 1) {
                return (char) (array[i] + 1);
            }
        }
        return ' ';
    }

    public static void main(String[] args) {
        System.out.println(findMissingLetter(new char[] {'a','b','c','d','f'}));  // Output: e
        System.out.println(findMissingLetter(new char[] {'O','Q','R','S'}));  // Output: P
    }
}
