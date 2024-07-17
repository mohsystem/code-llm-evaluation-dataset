import java.util.HashSet;

class PangramChecker {
    public static void main(String[] args) {
        String input = "The quick brown fox jumps over the lazy dog";
        boolean isPangram = isPangram(input);
        System.out.println(isPangram);
    }
    public static boolean isPangram(String text) {
        if (text.length() < 26) {
            return false;
        }
        text = text.toLowerCase();
        HashSet<Character> letters = new HashSet<>();
        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                letters.add(c);
            }
        }
        return letters.size() == 26;
    }
}