public class Main {
    public static int largestProduct(String inputStr, int span) {
        int maxProduct = 0;
        for (int i = 0; i <= inputStr.length() - span; i++) {
            int product = 1;
            for (int j = 0; j < span; j++) {
                product *= inputStr.charAt(i + j) - '0';
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
        }
        return maxProduct;
    }

    public static void main(String[] args) {
        String inputStr = "63915";
        int span = 3;
        System.out.println(largestProduct(inputStr, span));
    }
}