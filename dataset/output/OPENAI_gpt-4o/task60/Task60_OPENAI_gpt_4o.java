public class Task60_OPENAI_gpt_4o {
    public static String expandedForm(int num) {
        String numStr = Integer.toString(num);
        StringBuilder result = new StringBuilder();
        int length = numStr.length();
        for (int i = 0; i < length; i++) {
            char digit = numStr.charAt(i);
            if (digit != '0') {
                result.append(digit).append("0".repeat(length - i - 1)).append(" + ");
            }
        }
        return result.toString().substring(0, result.length() - 3);
    }

    public static void main(String[] args) {
        System.out.println(Task60_OPENAI_gpt_4o.expandedForm(12));   // Should return "10 + 2"
        System.out.println(Task60_OPENAI_gpt_4o.expandedForm(42));   // Should return "40 + 2"
        System.out.println(Task60_OPENAI_gpt_4o.expandedForm(70304));// Should return "70000 + 300 + 4"
    }
}