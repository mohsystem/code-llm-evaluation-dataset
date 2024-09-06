import java.lang.Math;

public class Task167_MISTRAL_codestral_latest {
    public static double cubeDiagonal(double volume) {
        double sideLength = Math.cbrt(volume);
        double diagonalLength = Math.round(sideLength * Math.sqrt(3) * 100.0) / 100.0;
        return diagonalLength;
    }
}