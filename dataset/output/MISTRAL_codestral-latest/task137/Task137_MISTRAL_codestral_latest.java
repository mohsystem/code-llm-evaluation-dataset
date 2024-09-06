// Java

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task137_MISTRAL_codestral_latest {
    private static Map<String, Map<String, Object>> productTable = new HashMap<>();

    static {
        // Initialize product table
        Map<String, Object> product1 = new HashMap<>();
        product1.put("name", "Product 1");
        product1.put("price", 10.99);
        product1.put("quantity", 100);

        Map<String, Object> product2 = new HashMap<>();
        product2.put("name", "Product 2");
        product2.put("price", 20.99);
        product2.put("quantity", 50);

        productTable.put("P123", product1);
        productTable.put("P456", product2);
        // Add more products as needed
    }

    public static Map<String, Object> getProductDetails(String productId) {
        return productTable.getOrDefault(productId, null);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get user input
        System.out.print("Enter product ID: ");
        String productId = scanner.nextLine();

        // Get product details
        Map<String, Object> productDetails = getProductDetails(productId);

        // Print product details
        if (productDetails != null) {
            System.out.println("Name: " + productDetails.get("name"));
            System.out.println("Price: " + productDetails.get("price"));
            System.out.println("Quantity: " + productDetails.get("quantity"));
        } else {
            System.out.println("Product not found");
        }

        scanner.close();
    }
}