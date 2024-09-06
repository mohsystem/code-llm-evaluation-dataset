// Java
import java.util.Scanner;
import java.io.Console;

public class Task124_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Console console = System.console();
        if (console == null) {
            System.out.println("Couldn't get Console instance");
            System.exit(0);
        }

        char[] passwordArray = console.readPassword("Password: ");
        String password = new String(passwordArray);
    }
}