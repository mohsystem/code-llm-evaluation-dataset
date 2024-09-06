// Java code
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task137_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Map<String, Map<String, Integer>> productTable = new HashMap<>();
        productTable.put("apple", Map.of("price", 10, "stock", 100));
        productTable.put("banana", Map.of("price", 5, "stock", 200));
        productTable.put("orange", Map.of("price", 15, "stock", 50));

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter product name: ");
        String productName = scanner.nextLine();

        if (productTable.containsKey(productName)) {
            System.out.println("Product: " + productName);
            System.out.println("Price: " + productTable.get(productName).get("price"));
            System.out.println("Stock: " + productTable.get(productName).get("stock"));
        } else {
            System.out.println("Product not found");
        }
    }
}