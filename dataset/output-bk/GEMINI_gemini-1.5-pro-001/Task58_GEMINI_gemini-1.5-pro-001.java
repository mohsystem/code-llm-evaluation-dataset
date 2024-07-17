public class Main {
    public static boolean XO(String str) {
        int xCount = 0;
        int oCount = 0;

        for (char c : str.toLowerCase().toCharArray()) {
            if (c == 'x') {
                xCount++;
            } else if (c == 'o') {
                oCount++;
            }
        }

        return xCount == oCount;
    }

    public static void main(String[] args) {
        System.out.println(XO("ooxx")); // true
        System.out.println(XO("xooxx")); // false
        System.out.println(XO("ooxXm")); // true
        System.out.println(XO("zpzpzpp")); // true
        System.out.println(XO("zzoo")); // false
    }
}