public class Task146_MISTRAL_codestral_latest {
    public static int findMissing(int[] arr) {
        int n = arr.length + 1;
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return total - sum;
    }
}