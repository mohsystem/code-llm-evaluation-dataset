public class Task183_GEMINI_gemini_1_5_pro_001 {
    public static int largestProduct(String digits, int span) {
        if (digits.length() < span || span < 1) {
            return 0;
        }
        int maxProduct = 0;
        for (int i = 0; i <= digits.length() - span; i++) {
            int product = 1;
            for (int j = i; j < i + span; j++) {
                product *= Character.getNumericValue(digits.charAt(j));
            }
            maxProduct = Math.max(maxProduct, product);
        }
        return maxProduct;
    }

    public static void main(String[] args) {
        String digits = "63915";
        int span = 3;
        int result = largestProduct(digits, span);
        System.out.println(result);
    }
}