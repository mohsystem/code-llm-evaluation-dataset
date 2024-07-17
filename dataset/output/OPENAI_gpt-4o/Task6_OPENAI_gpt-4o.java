public class UnifiedSourceCode {
    public static void main(String[] args) {
        System.out.println("Java unique number: " + findUniqJava(new double[]{1, 1, 1, 2, 1, 1}));
        System.out.println("C unique number: " + findUniqC(new double[]{0, 0, 0.55, 0, 0}, 5));
        System.out.println("C++ unique number: " + findUniqCpp(new double[]{1, 1, 1, 2, 1, 1}));
        System.out.println("Python unique number: " + findUniqPython(new double[]{0, 0, 0.55, 0, 0}));
    }

    public static double findUniqJava(double[] arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        for (double v : arr) if (v != arr[0]) return v;
        return -1; // Just a default case, won't reach here
    }

    public static native double findUniqC(double[] arr, int size);

    static {
        System.loadLibrary("UnifiedSourceCode");
    }

    public static double findUniqCpp(double[] arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        for (double v : arr) if (v != arr[0]) return v;
        return -1; // Just a default case, won't reach here
    }

    public static double findUniqPython(double[] arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        for (double v : arr) if (v != arr[0]) return v;
        return -1; // Just a default case, won't reach here
    }
}