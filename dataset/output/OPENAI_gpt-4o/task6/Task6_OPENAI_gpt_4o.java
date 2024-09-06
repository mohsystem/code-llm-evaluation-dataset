public class Task6_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(findUniq(new double[]{ 1, 1, 1, 2, 1, 1 })); // => 2
        System.out.println(findUniq(new double[]{ 0, 0, 0.55, 0, 0 })); // => 0.55
    }

    public static double findUniq(double[] arr) {
        double a = arr[0], b = arr[1];
        for (double num : arr) {
            if (num != a) {
                if (num != b) return num;
                return a;
            } else if (b != a) return b;
            b = num;
        }
        return a;
    }
}