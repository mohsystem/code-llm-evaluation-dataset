// Java
import java.util.Scanner;

public class AdminPassword {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter admin password: ");
        String password = scanner.nextLine();

        if (password.equals("admin123")) {
            System.out.println("Password is valid.");
        } else {
            System.out.println("Password is invalid.");
        }
    }
}