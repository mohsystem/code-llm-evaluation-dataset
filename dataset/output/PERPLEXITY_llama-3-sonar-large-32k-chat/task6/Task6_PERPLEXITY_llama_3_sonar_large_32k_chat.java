public class Task6_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static double findUniq(double arr[]) {
        double a = arr[0];
        double b = arr[1];
        if (a == b) {
            for (int i = 2; i < arr.length; i++) {
                if (arr[i] != a) {
                    return arr[i];
                }
            }
        } else {
            for (int i = 2; i < arr.length; i++) {
                if (arr[i] == a) {
                    return b;
                } else {
                    return a;
                }
            }
        }
        return 0;
    }
}