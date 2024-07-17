// Java code
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ProductInquiry {
    public static void main(String[] args) {
        Map<String, Map<String, Double>> productTable = new HashMap<>();
        productTable.put("apple", Map.of("price", 1.00, "stock", 100.0));
        productTable.put("banana", Map.of("price", 0.50, "stock", 200.0));
        productTable.put("orange", Map.of("price", 1.50, "stock", 50.0));

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