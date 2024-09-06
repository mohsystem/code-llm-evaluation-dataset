
public class Task183_CLAUDE_claude_3_5_sonnet_20240620 {
    public static long largestSeriesProduct(String inputSequence, int span) {
        if (span > inputSequence.length() || span <= 0) {
            return -1; // Invalid input
        }
        
        long maxProduct = 0;
        
        for (int i = 0; i <= inputSequence.length() - span; i++) {
            String series = inputSequence.substring(i, i + span);
            long product = 1;
            for (char digit : series.toCharArray()) {
                product *= Character.getNumericValue(digit);
            }
            maxProduct = Math.max(maxProduct, product);
        }
        
        return maxProduct;
    }
    
    public static void main(String[] args) {
        String inputSequence = "63915";
        int span = 3;
        long result = largestSeriesProduct(inputSequence, span);
        System.out.printf("The largest product of %d adjacent digits in %s is: %d%n", span, inputSequence, result);
    }
}
