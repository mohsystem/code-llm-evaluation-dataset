import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, String> resources = new HashMap<>();
        resources.put("resource1", "Access to Resource 1");
        resources.put("resource2", "Access to Resource 2");

        System.out.print("Enter your resource: ");
        String userInput = scanner.nextLine();
        System.out.println(resources.getOrDefault(userInput, "Resource not found"));
    }
}