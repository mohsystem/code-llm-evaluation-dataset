public class Kata {
    public static double findUniq(double[] arr) {
        double a = arr[0];
        double b = arr[1];
        if (a == b) {
            for (int i = 2; i < arr.length; i++) {
                if (arr[i] != a) return arr[i];
            }
        } else {
            for (int i = 2; i < arr.length; i++) {
                if (arr[i] == a) return b;
                if (arr[i] == b) return a;
            }
        }
        return -1; // not found
    }
}