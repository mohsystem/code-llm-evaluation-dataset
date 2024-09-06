
import java.lang.Math;

public class Task167_CLAUDE_claude_3_5_sonnet_20240620 {
    public static double cubeDiagonal(double volume) {
        double side = Math.cbrt(volume);
        double diagonal = Math.sqrt(3) * side;
        return Math.round(diagonal * 100.0) / 100.0;
    }
}
