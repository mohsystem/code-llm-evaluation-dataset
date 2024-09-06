
import java.util.Scanner;
import java.io.Console;

public class Task125_CLAUDE_claude_3_5_sonnet_20240620 {
    private static boolean authenticate() {
        Scanner scanner = new Scanner(System.in);
        Console console = System.console();
        
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        
        char[] passwordChars = console.readPassword("Enter password: ");
        String password = new String(passwordChars);
        
        return username.equals("admin") && password.equals("password123");
    }
    
    private static void accessResource(String resource) {
        switch (resource) {
            case "1":
                System.out.println("Accessing confidential files...");
                break;
            case "2":
                System.out.println("Accessing financial records...");
                break;
            case "3":
                System.out.println("Accessing employee database...");
                break;
            default:
                System.out.println("Invalid resource selection.");
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (authenticate()) {
            System.out.println("Authentication successful.");
            while (true) {
                System.out.println("\\nAvailable resources:");
                System.out.println("1. Confidential files");
                System.out.println("2. Financial records");
                System.out.println("3. Employee database");
                System.out.println("4. Exit");
                System.out.print("Enter resource number to access (or 4 to exit): ");
                String choice = scanner.nextLine();
                if (choice.equals("4")) {
                    break;
                }
                accessResource(choice);
            }
        } else {
            System.out.println("Authentication failed. Access denied.");
        }
        
        scanner.close();
    }
}
