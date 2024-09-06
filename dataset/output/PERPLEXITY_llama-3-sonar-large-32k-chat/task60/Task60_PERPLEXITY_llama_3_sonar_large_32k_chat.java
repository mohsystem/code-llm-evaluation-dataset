public class Task60_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String expandedForm(int num) {
        String numStr = String.valueOf(num);
        String result = "";
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr.charAt(i) != '0') {
                result += numStr.charAt(i);
                for (int j = 0; j < numStr.length() - i - 1; j++) {
                    result += "0";
                }
                result += " + ";
            }
        }
        return result.substring(0, result.length() - 3);
    }
}