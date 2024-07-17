public class Main {
    public static int largestProduct(String digits, int span) {
        if (span < 1 || span > digits.length()) {
            return -1;
        }
        int maxProduct = 0;
        for (int i = 0; i <= digits.length() - span; i++) {
            int product = 1;
            for (int j = i; j < i + span; j++) {
                product *= Integer.parseInt(String.valueOf(digits.charAt(j)));
            }
            maxProduct = Math.max(maxProduct, product);
        }
        return maxProduct;
    }

    public static void main(String[] args) {
        // Example usage:
        String digits = "63915";
        int span = 3;
        int result = largestProduct(digits, span);
        System.out.println("Largest product: " + result);
    }
}