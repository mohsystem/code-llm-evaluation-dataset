public class Task26_GEMINI_gemini_1_5_pro_001 {
    public static int findIt(int[] arr) {
        int result = 0;
        for (int j : arr) {
            result ^= j;
        }
        return result;
    }
}