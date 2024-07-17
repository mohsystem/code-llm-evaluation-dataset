// Java

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Assuming we have a HashMap as our product table
        Map<String, Map<String, Integer>> productTable = new HashMap<>();
        Map<String, Integer> product1 = new HashMap<>();
        product1.put("price", 10);
        product1.put("quantity", 50);
        productTable.put("product1", product1);
        // Add more products as needed

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter product name: ");
        String productName = scanner.nextLine();
        System.out.println(getProductDetails(productTable, productName));
    }

    public static String getProductDetails(Map<String, Map<String, Integer>> productTable, String productName) {
        return productTable.containsKey(productName) ? productTable.get(productName).toString() : "Product not found";
    }
}