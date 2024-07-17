import java.lang.Math;
class CubeDiagonal {
  public static double cubeDiagonal(double volume) {
    return Math.round(Math.sqrt(3) * Math.pow(volume, 1.0/3) * 100.0) / 100.0;
  }
  public static void main(String[] args) {
  }
}