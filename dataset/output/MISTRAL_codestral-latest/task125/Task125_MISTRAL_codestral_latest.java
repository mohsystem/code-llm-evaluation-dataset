// Java

import java.util.HashMap;
import java.util.Scanner;

public class Task125_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        HashMap<String, String> resources = new HashMap<>();
        resources.put("A", "Resource A");
        resources.put("B", "Resource B");
        resources.put("C", "Resource C");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a key to access a resource: ");
        String userInput = scanner.nextLine();

        if (resources.containsKey(userInput)) {
            System.out.println("Access granted to: " + resources.get(userInput));
        } else {
            System.out.println("Access denied. Invalid key.");
        }
    }
}