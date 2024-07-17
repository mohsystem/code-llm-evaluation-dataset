import java.util.Random;

class Solution {
    private double radius;
    private double x_center;
    private double y_center;
    private Random rand;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
        this.rand = new Random();
    }

    public double[] randPoint() {
        double angle = 2 * Math.PI * rand.nextDouble();
        double hyp = Math.sqrt(rand.nextDouble()) * radius;
        double x = x_center + hyp * Math.cos(angle);
        double y = y_center + hyp * Math.sin(angle);
        return new double[]{x, y};
    }
}