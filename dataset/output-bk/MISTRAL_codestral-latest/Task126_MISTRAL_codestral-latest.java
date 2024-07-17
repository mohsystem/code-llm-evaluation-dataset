import java.util.Scanner;

public class RedirectUser {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a page: ");
        String input = scanner.nextLine();

        if (input.equals("home")) {
            System.out.println("Redirecting to home page...");
        } else if (input.equals("about")) {
            System.out.println("Redirecting to about page...");
        } else if (input.equals("contact")) {
            System.out.println("Redirecting to contact page...");
        } else {
            System.out.println("Invalid input. Staying on current page.");
        }
    }
}