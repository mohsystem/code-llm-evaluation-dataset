import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an integer: ");
        try {
            int number = scanner.nextInt();
            System.out.println("The entered integer is: " + number);
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter an integer.");
        }
    }
}