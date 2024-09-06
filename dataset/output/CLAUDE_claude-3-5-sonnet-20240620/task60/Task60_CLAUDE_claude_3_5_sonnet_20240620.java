
public class Task60_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String expandedForm(int num) {
        StringBuilder result = new StringBuilder();
        String numStr = String.valueOf(num);
        
        for (int i = 0; i < numStr.length(); i++) {
            char digit = numStr.charAt(i);
            if (digit != '0') {
                if (result.length() > 0) {
                    result.append(" + ");
                }
                result.append(digit);
                for (int j = 0; j < numStr.length() - i - 1; j++) {
                    result.append('0');
                }
            }
        }
        
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(expandedForm(12));    // Output: 10 + 2
        System.out.println(expandedForm(42));    // Output: 40 + 2
        System.out.println(expandedForm(70304)); // Output: 70000 + 300 + 4
    }
}
