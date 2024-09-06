import java.util.Scanner;

public class Task73_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the admin password: ");
        String inputPassword = sc.nextLine();

        System.out.println(checkPassword(inputPassword));
    }

    public static String checkPassword(String password) {
        String adminPassword = "admin123";
        if (password.equals(adminPassword)) {
            return "Password is valid";
        } else {
            return "Password is invalid";
        }
    }
}