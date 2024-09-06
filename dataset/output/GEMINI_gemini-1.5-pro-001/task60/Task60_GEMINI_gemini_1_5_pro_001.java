public class Task60_GEMINI_gemini_1_5_pro_001 {
    public static String expandedForm(int num) {
        String numStr = String.valueOf(num);
        int length = numStr.length();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < length; i++) {
            char digit = numStr.charAt(i);
            if (digit != '0') {
                if (result.length() > 0) {
                    result.append(" + ");
                }
                result.append(digit);
                for (int j = i + 1; j < length; j++) {
                    result.append('0');
                }
            }
        }
        return result.toString();
    }
}