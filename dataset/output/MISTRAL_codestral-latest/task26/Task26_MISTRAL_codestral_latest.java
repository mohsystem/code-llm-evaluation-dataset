public class Task26_MISTRAL_codestral_latest {
    public static int findIt(int[] seq) {
        for (int i : seq) {
            int count = 0;
            for (int j : seq) {
                if (i == j) {
                    count++;
                }
            }
            if (count % 2 != 0) {
                return i;
            }
        }
        return -1;
    }
}