public class Task34_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean narcissistic(int value) {
        int sum = 0;
        String strValue = String.valueOf(value);
        for (char digit : strValue.toCharArray()) {
            sum += Math.pow(Character.getNumericValue(digit), strValue.length());
        }
        return value == sum;
    }
}