public class Task8_OPENAI_gpt_4o {
    public static char findMissingLetter(char[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i + 1] - array[i] != 1) {
                return (char) (array[i] + 1);
            }
        }
        throw new IllegalArgumentException("No missing letter found");
    }

    public static void main(String[] args) {
        System.out.println(findMissingLetter(new char[] { 'a', 'b', 'c', 'd', 'f' })); // e
        System.out.println(findMissingLetter(new char[] { 'O', 'Q', 'R', 'S' })); // P
    }
}