
public class CubeDiagonal {
    public static double cubeDiagonal(double volume) {
        double side = Math.cbrt(volume);
        double diagonal = Math.sqrt(3) * side;
        return Math.round(diagonal * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        System.out.println(cubeDiagonal(8));
        System.out.println(cubeDiagonal(343));
        System.out.println(cubeDiagonal(1157.625));
    }
}
