
public class Task114_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        // String copy
        String original = "Hello, World!";
        String copied = new String(original);
        System.out.println("Original: " + original);
        System.out.println("Copied: " + copied);

        // String concatenation
        String str1 = "Java ";
        String str2 = "is awesome!";
        String concatenated = str1 + str2;
        System.out.println("Concatenated: " + concatenated);

        // String manipulation
        String text = "   Java Programming   ";
        String stripped = text.trim();
        String upper = text.toUpperCase();
        String lower = text.toLowerCase();
        String replaced = text.replace("Java", "Python");

        System.out.println("Stripped: '" + stripped + "'");
        System.out.println("Uppercase: " + upper);
        System.out.println("Lowercase: " + lower);
        System.out.println("Replaced: " + replaced);
    }
}
