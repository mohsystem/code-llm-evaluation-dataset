public class Main {
    public static boolean isPangram(String input) {
        input = input.toLowerCase();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (input.indexOf(ch) < 0) {
                return false;
            }
        }
        return true;
    }
}