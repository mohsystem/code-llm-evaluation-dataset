public class Kata {
    public static String expandedForm(int num) {
        String result = "";
        String numStr = String.valueOf(num);
        int length = numStr.length();
        for (int i = 0; i < length; i++) {
            char c = numStr.charAt(i);
            if (c != '0') {
                int zeros = length - i - 1;
                result += c;
                for (int j = 0; j < zeros; j++) {
                    result += "0";
                }
                if (i < length - 1) {
                    result += " + ";
                }
            }
        }
        return result.endsWith(" + ") ? result.substring(0, result.length() - 3) : result;
    }

    public static void main(String[] args) {
        System.out.println(Kata.expandedForm(12)); // Should return "10 + 2"
        System.out.println(Kata.expandedForm(42)); // Should return "40 + 2"
        System.out.println(Kata.expandedForm(70304)); // Should return "70000 + 300 + 4"
    }
}