code here:
public class Task114_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        String s1 = "Hello";
        String s2 = "World";
        System.out.println("Original Strings:");
        System.out.println("s1: " + s1);
        System.out.println("s2: " + s2);

        // Copying a string
        String s3 = s1;
        System.out.println("\nCopied String:");
        System.out.println("s3: " + s3);

        // Concatenating strings
        String s4 = s1 + " " + s2;
        System.out.println("\nConcatenated String:");
        System.out.println("s4: " + s4);

        // Manipulating strings (upper case)
        String s5 = s1.toUpperCase();
        System.out.println("\nUpper Case String:");
        System.out.println("s5: " + s5);

        // Manipulating strings (lower case)
        String s6 = s2.toLowerCase();
        System.out.println("\nLower Case String:");
        System.out.println("s6: " + s6);
    }
}