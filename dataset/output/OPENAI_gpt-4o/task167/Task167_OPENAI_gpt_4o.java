import java.lang.Math;

public class Task167_OPENAI_gpt_4o {
    public static double cubeDiagonal(double volume) {
        double side_length = Math.cbrt(volume);
        double diagonal_length = side_length * Math.sqrt(3);
        return Math.round(diagonal_length * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        System.out.println(cubeDiagonal(8));
        System.out.println(cubeDiagonal(343));
        System.out.println(cubeDiagonal(1157.625));
    }
}