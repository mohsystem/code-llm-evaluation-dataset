public class Main {
    public static void main(String[] args) {
        System.out.println(findMissingLetter(new char[]{'a','b','c','d','f'}));  // 'e'
        System.out.println(findMissingLetter(new char[]{'O','Q','R','S'}));  // 'P'
    }

    public static char findMissingLetter(char[] chars) {
        for (int i = 0; i < chars.length - 1; i++) {
            if (chars[i + 1] - chars[i] > 1) {
                return (char) (chars[i] + 1);
            }
        }
        return '\0';
    }
}