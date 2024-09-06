import java.util.Random;

class Solution {
    private double radius;
    private double xCenter;
    private double yCenter;
    private Random rand;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.xCenter = x_center;
        this.yCenter = y_center;
        this.rand = new Random();
    }

    public double[] randPoint() {
        double angle = rand.nextDouble() * 2 * Math.PI;
        double r = Math.sqrt(rand.nextDouble()) * radius;
        double x = xCenter + r * Math.cos(angle);
        double y = yCenter + r * Math.sin(angle);
        return new double[] { x, y };
    }
}