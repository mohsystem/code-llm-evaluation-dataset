// Java
import java.util.Scanner;

public class Task41_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String inputString = scanner.nextLine();
        processString(inputString);
    }

    public static void processString(String inputString) {
        // Process the string here
        System.out.println("Processed string: " + inputString);
    }
}

// Java is safe from buffer overflow as it uses String objects which are dynamically resized