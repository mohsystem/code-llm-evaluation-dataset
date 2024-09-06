public class Task58_OPENAI_gpt_4o {
    public static boolean XO(String s) {
        s = s.toLowerCase();
        long xCount = s.chars().filter(ch -> ch == 'x').count();
        long oCount = s.chars().filter(ch -> ch == 'o').count();
        return xCount == oCount;
    }

    public static void main(String[] args) {
        System.out.println(XO("ooxx"));  // True
        System.out.println(XO("xooxx"));  // False
        System.out.println(XO("ooxXm"));  // True
        System.out.println(XO("zpzpzpp"));  // True
        System.out.println(XO("zzoo"));  // False
    }
}