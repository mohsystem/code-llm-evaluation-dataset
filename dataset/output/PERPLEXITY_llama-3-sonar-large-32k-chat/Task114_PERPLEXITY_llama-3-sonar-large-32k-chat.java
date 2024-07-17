public class Main {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "World";
        
        // Copying a string
        String str3 = str1;
        System.out.println("Copied string: " + str3);
        
        // Concatenating strings
        String str4 = str1 + " " + str2;
        System.out.println("Concatenated string: " + str4);
        
        // Manipulating strings (upper case)
        String str5 = str1.toUpperCase();
        System.out.println("Upper case string: " + str5);
        
        // Manipulating strings (lower case)
        String str6 = str2.toLowerCase();
        System.out.println("Lower case string: " + str6);
    }
}