public class Task13_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean isValidWalk(String[] walk) {
        int n = 0, s = 0, e = 0, w = 0;
        for (String dir : walk) {
            if (dir.equals("n")) n++;
            if (dir.equals("s")) s++;
            if (dir.equals("e")) e++;
            if (dir.equals("w")) w++;
        }
        return walk.length == 10 && n == s && e == w;
    }
}