public class Task60_MISTRAL_codestral_latest {
    public static String expandedForm(int num) {
        StringBuilder expanded = new StringBuilder();
        String numStr = Integer.toString(num);
        for (int i = 0; i < numStr.length(); i++) {
            char digit = numStr.charAt(i);
            if (digit != '0') {
                if (expanded.length() > 0) {
                    expanded.append(" + ");
                }
                expanded.append(digit);
                for (int j = 0; j < numStr.length() - i - 1; j++) {
                    expanded.append("0");
                }
            }
        }
        return expanded.toString();
    }
}