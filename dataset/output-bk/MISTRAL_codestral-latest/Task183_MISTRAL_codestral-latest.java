public class MaxProduct {
    public static int maxProduct(String input, int span) {
        int maxProd = 0;
        for (int i = 0; i <= input.length() - span; i++) {
            int prod = 1;
            for (int j = i; j < i + span; j++) {
                prod *= Character.getNumericValue(input.charAt(j));
            }
            maxProd = Math.max(maxProd, prod);
        }
        return maxProd;
    }
}