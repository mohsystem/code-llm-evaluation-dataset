import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Task125_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Map<String, List<String>> roles = new HashMap<>();
        roles.put("admin", List.of("resource1", "resource2", "resource3"));
        roles.put("editor", List.of("resource2", "resource3"));
        roles.put("viewer", List.of("resource3"));

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your role (admin, editor, viewer): ");
        String userRole = scanner.nextLine();

        if (roles.containsKey(userRole)) {
            System.out.println("Available resources for " + userRole + ":");
            for (String resource : roles.get(userRole)) {
                System.out.println(resource);
            }
        } else {
            System.out.println("Invalid role.");
        }
    }
}