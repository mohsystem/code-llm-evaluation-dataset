import java.util.Scanner;

public class RedirectUser {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'exit' to exit: ");
        String userInput = scanner.nextLine();
        if (userInput.equals("google")) {
            System.out.println("Redirecting to Google...");
        } else if (userInput.equals("facebook")) {
            System.out.println("Redirecting to Facebook...");
        } else if (userInput.equals("exit")) {
            System.out.println("Exiting...");
        } else {
            System.out.println("Invalid input. Please try again.");
            main(args);
        }
    }
}