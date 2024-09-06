import java.util.Scanner;

public class Task103_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        if (password.length() >= 8 && 
            password.chars().anyMatch(Character::isLowerCase) &&
            password.chars().anyMatch(Character::isUpperCase) &&
            password.chars().anyMatch(Character::isDigit)) {
            System.out.println("Password is strong.");
        } else {
            System.out.println("Password is weak.");
        }
    }
}