
public class Kata {
    public static String expandedForm(int num) {
        StringBuilder result = new StringBuilder();
        String numStr = String.valueOf(num);
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr.charAt(i) != \'0\') {
                if (result.length() > 0) {
                    result.append(" + ");
                }
                result.append(numStr.charAt(i));
                result.append("0".repeat(numStr.length() - i - 1));
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(expandedForm(12));
        System.out.println(expandedForm(42));
        System.out.println(expandedForm(70304));
    }
}
