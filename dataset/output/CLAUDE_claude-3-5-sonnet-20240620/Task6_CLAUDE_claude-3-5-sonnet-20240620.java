
public class Kata {
    public static double findUniq(double[] arr) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        if (arr[1] != arr[0] && arr[1] != arr[2]) return arr[1];
        
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] != arr[0]) return arr[i];
        }
        
        return arr[0];
    }

    public static void main(String[] args) {
        System.out.println(findUniq(new double[]{ 1, 1, 1, 2, 1, 1 }));
        System.out.println(findUniq(new double[]{ 0, 0, 0.55, 0, 0 }));
    }
}
