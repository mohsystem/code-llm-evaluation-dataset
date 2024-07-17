public class Main {
    public static int largestProduct(String digits, int span) {
        if (span == 0) {
            return 1;
        }
        int maxProduct = 0;
        for (int i = 0; i <= digits.length() - span; i++) {
            int product = 1;
            for (int j = i; j < i + span; j++) {
                product *= Character.getNumericValue(digits.charAt(j));
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
        }
        return maxProduct;
    }

    public static void main(String[] args) {
        String digits = "63915";
        int span = 3;
        System.out.println(largestProduct(digits, span));
    }
}