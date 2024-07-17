
public class StringOperations {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "World";

        // Copy
        String copy = new String(str1);

        // Concatenate
        String concat = str1 + " " + str2;

        // Manipulate
        String upper = concat.toUpperCase();
        String sub = concat.substring(0, 5);
        String replace = concat.replace(\'o\', \'0\');

        System.out.println("Original: " + str1 + ", " + str2);
        System.out.println("Copy: " + copy);
        System.out.println("Concatenated: " + concat);
        System.out.println("Uppercase: " + upper);
        System.out.println("Substring: " + sub);
        System.out.println("Replaced: " + replace);
    }
}
