public class StringOperations {
    public static void main(String[] args) {
        // Copying a string
        String str1 = "Hello";
        String str2 = str1;
        System.out.println("Copied string: " + str2);

        // Concatenating strings
        String str3 = " World";
        String str4 = str1 + str3;
        System.out.println("Concatenated string: " + str4);

        // Manipulating strings
        String str5 = "Java Programming";
        System.out.println("Length of the string: " + str5.length());
        System.out.println("Substring: " + str5.substring(5));
        System.out.println("Uppercase: " + str5.toUpperCase());
        System.out.println("Lowercase: " + str5.toLowerCase());
    }
}