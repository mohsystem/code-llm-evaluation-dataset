// Java
public class StringOperations {

    public static void java_string_operations() {
        String str1 = "Hello";
        String str2 = "World";
        String copied_str = str1;
        String concatenated_str = str1 + " " + str2;
        StringBuilder manipulated_str = new StringBuilder(str1).reverse().append(" ").append(str2.toUpperCase());
        System.out.println("Java - Copied: " + copied_str);
        System.out.println("Java - Concatenated: " + concatenated_str);
        System.out.println("Java - Manipulated: " + manipulated_str.toString());
    }

    public static void main(String[] args) {
        java_string_operations();
    }
}