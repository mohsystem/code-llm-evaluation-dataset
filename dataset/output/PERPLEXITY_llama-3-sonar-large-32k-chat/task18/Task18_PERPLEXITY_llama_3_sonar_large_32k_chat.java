public class Task18_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int binaryArrayToNumber(int[] arr) {
        String binaryString = "";
        for (int i : arr) {
            binaryString += i;
        }
        return Integer.parseInt(binaryString, 2);
    }
}