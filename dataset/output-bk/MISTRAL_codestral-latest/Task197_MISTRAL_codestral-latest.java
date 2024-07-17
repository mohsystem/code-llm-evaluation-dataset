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
        double r = this.radius * Math.sqrt(this.rand.nextDouble());
        double theta = this.rand.nextDouble() * 2 * Math.PI;
        double x = this.x_center + r * Math.cos(theta);
        double y = this.y_center + r * Math.sin(theta);
        return new double[]{x, y};
    }
}