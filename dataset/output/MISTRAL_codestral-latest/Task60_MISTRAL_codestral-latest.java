// Java
public class Kata {
    public static String expandedForm(int num) {
        StringBuilder sb = new StringBuilder();
        int[] digits = {10000, 1000, 100, 10, 1};
        for (int digit : digits) {
            if (num >= digit) {
                int count = num / digit;
                sb.append(count * digit);
                num -= count * digit;
                if (num > 0) {
                    sb.append(" + ");
                }
            }
        }
        return sb.toString();
    }
}