public class Task183_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String sequence = "63915";
        int span = 3;
        System.out.println(findLargestProduct(sequence, span));
    }

    public static int findLargestProduct(String sequence, int span) {
        int maxProduct = 0;
        for (int i = 0; i <= sequence.length() - span; i++) {
            int product = 1;
            for (int j = 0; j < span; j++) {
                product *= Character.getNumericValue(sequence.charAt(i + j));
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
        }
        return maxProduct;
    }
}