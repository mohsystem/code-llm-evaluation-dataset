import java.util.Scanner;

public class MultiLangProgram {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Java code
        System.out.println("Enter a string (Java):");
        String inputJava = scanner.nextLine();
        System.out.println("You entered (Java): " + inputJava);

        // Call C function
        processStringC(inputJava);

        // Call C++ function
        processStringCpp(inputJava);

        // Call Python function
        processStringPython(inputJava);
        
        scanner.close();
    }

    // Native method declarations
    public static native void processStringC(String input);
    public static native void processStringCpp(String input);
    public static native void processStringPython(String input);

    static {
        System.loadLibrary("MultiLangProgram");  // Load native library
    }
}