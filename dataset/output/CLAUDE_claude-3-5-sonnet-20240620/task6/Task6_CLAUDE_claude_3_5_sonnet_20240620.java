
public class Task6_CLAUDE_claude_3_5_sonnet_20240620 {
    public static double findUniq(double[] arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[0]) return arr[i];
        }
        return arr[0];  // This line should never be reached given the problem constraints
    }

    public static void main(String[] args) {
        System.out.println(findUniq(new double[]{ 1, 1, 1, 2, 1, 1 }));  // Output: 2.0
        System.out.println(findUniq(new double[]{ 0, 0, 0.55, 0, 0 }));  // Output: 0.55
    }
}
