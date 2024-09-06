public class Task27_MISTRAL_codestral_latest {
    public static int find(int[] integers) {
        int evens = 0, odds = 0, even = 0, odd = 0;
        for (int i = 0; i < integers.length; i++) {
            if (integers[i] % 2 == 0) {
                evens++;
                even = integers[i];
            } else {
                odds++;
                odd = integers[i];
            }
        }
        return evens < odds ? even : odd;
    }
}