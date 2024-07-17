public class Kata {
    public static String expandedForm(int num) {
        String str = "";
        int len = String.valueOf(num).length();
        for (int i = 0; i < len; i++) {
            int digit = (int) (num / Math.pow(10, len - i - 1)) % 10;
            if (digit != 0) {
                str += digit * Math.pow(10, len - i - 1);
                if (i != len - 1) {
                    str += " + ";
                }
            }
        }
        return str;
    }

    public static void main(String[] args) {
        System.out.println(expandedForm(12));
        System.out.println(expandedForm(42));
        System.out.println(expandedForm(70304));
    }
}