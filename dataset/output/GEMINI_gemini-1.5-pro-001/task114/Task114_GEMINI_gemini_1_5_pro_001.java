public class Task114_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        // String declaration and initialization
        String str1 = "Hello";
        String str2 = "World";

        // String concatenation
        String concatenatedString = str1 + " " + str2;
        System.out.println("Concatenated String: " + concatenatedString);

        // String copying
        String copiedString = str1;
        System.out.println("Copied String: " + copiedString);

        // String length
        int length = concatenatedString.length();
        System.out.println("Length of Concatenated String: " + length);

        // String manipulation - uppercase
        String uppercaseString = concatenatedString.toUpperCase();
        System.out.println("Uppercase String: " + uppercaseString);

        // String manipulation - lowercase
        String lowercaseString = concatenatedString.toLowerCase();
        System.out.println("Lowercase String: " + lowercaseString);

        // Substring extraction
        String substring = concatenatedString.substring(0, 5);
        System.out.println("Substring: " + substring);
    }
}