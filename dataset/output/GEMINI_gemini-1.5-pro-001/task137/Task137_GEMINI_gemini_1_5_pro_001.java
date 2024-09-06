import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task137_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        Map<String, Map<String, Object>> products = new HashMap<>();
        products.put("001", Map.of("name", "Apple", "price", 1.00, "stock", 100));
        products.put("002", Map.of("name", "Banana", "price", 0.50, "stock", 50));
        products.put("003", Map.of("name", "Orange", "price", 1.20, "stock", 75));

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter product ID (or 'q' to quit): ");
            String productId = scanner.nextLine();
            if (productId.equals("q")) {
                break;
            }
            System.out.println(getProductDetails(products, productId));
        }
    }

    private static String getProductDetails(Map<String, Map<String, Object>> products, String productId) {
        Map<String, Object> product = products.get(productId);
        if (product != null) {
            return String.format("Product Name: %s\nPrice: $%.2f\nStock: %d",
                    product.get("name"), product.get("price"), product.get("stock"));
        } else {
            return "Product not found.";
        }
    }
}