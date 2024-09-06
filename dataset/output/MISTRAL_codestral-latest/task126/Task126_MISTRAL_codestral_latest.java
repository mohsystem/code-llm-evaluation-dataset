// Java
import java.util.Scanner;

public class Task126_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your input: ");
        String userInput = scanner.nextLine();

        switch (userInput) {
            case "home":
                System.out.println("Redirecting to home page...");
                break;
            case "about":
                System.out.println("Redirecting to about page...");
                break;
            case "contact":
                System.out.println("Redirecting to contact page...");
                break;
            default:
                System.out.println("Invalid input. Redirecting to default page...");
        }
    }
}