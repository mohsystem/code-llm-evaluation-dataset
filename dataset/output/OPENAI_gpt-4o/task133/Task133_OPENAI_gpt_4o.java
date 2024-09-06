// Java
import java.util.Scanner;

public class Task133_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter your username: ");
        String username = scanner.nextLine();
        
        System.out.print("Enter your new password: ");
        String newPassword = scanner.nextLine();
        
        resetPassword(username, newPassword);
    }
    
    public static void resetPassword(String username, String newPassword) {
        System.out.println("Password for " + username + " has been reset to " + newPassword);
    }
}