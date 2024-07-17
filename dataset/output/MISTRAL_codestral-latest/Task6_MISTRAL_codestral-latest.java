// Java
public class Kata {
    public static double findUniq(double arr[]) {
        double a = arr[0];
        double b = arr[1];
        double c = arr[2];

        if (a != b && a != c) return a;
        if (a != b) return c;

        for (int i = 3; i < arr.length; i++) {
            if (arr[i] != a) return arr[i];
        }

        return -1;
    }
}