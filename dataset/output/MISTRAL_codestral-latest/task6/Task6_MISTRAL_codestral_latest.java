public class Task6_MISTRAL_codestral_latest {
    public static double findUniq(double arr[]) {
        double a = arr[0];
        double b = arr[1];
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] != a) {
                b = arr[i];
                break;
            }
        }
        return a if count(arr, a) == 1 else b;
    }

    public static int count(double arr[], double x) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        return count;
    }
}