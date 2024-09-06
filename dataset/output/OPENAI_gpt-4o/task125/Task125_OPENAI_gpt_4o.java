import java.util.Scanner;

public class Task125_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter user role (admin/user/guest): ");
        String userRole = scanner.nextLine().trim().toLowerCase();

        String result = accessResource(userRole);
        System.out.println(result);
    }

    public static String accessResource(String user) {
        switch (user) {
            case "admin":
                return "Access to administrative resources granted.";
            case "user":
                return "Access to user resources granted.";
            case "guest":
                return "Access to guest resources granted.";
            default:
                return "No resources available for this user role";
        }
    }
}