public class Task183_MISTRAL_codestral_latest {
    public static int maxProduct(String input, int span) {
        int maxProd = 0;
        for (int i = 0; i <= input.length() - span; i++) {
            String series = input.substring(i, i + span);
            int product = 1;
            for (char digit : series.toCharArray()) {
                product *= Character.getNumericValue(digit);
            }
            maxProd = Math.max(maxProd, product);
        }
        return maxProd;
    }
}