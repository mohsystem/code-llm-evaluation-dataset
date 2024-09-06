public class Task59_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(accum("abcd"));   // Output: A-Bb-Ccc-Dddd
        System.out.println(accum("RqaEzty")); // Output: R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
        System.out.println(accum("cwAt"));  // Output: C-Ww-Aaa-Tttt
    }

    public static String accum(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) result.append("-");
            result.append(Character.toUpperCase(s.charAt(i)));
            for (int j = 0; j < i; j++) {
                result.append(Character.toLowerCase(s.charAt(i)));
            }
        }
        return result.toString();
    }
}