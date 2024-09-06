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
        double r = radius * Math.sqrt(rand.nextDouble());
        double theta = 2 * Math.PI * rand.nextDouble();
        double x = x_center + r * Math.cos(theta);
        double y = y_center + r * Math.sin(theta);
        return new double[]{x, y};
    }

    public static void main(String[] args) {
        Solution sol = new Solution(1.0, 0.0, 0.0);
        double[] point1 = sol.randPoint();
        double[] point2 = sol.randPoint();
        double[] point3 = sol.randPoint();
        System.out.printf("Point1: [%f, %f]\n", point1[0], point1[1]);
        System.out.printf("Point2: [%f, %f]\n", point2[0], point2[1]);
        System.out.printf("Point3: [%f, %f]\n", point3[0], point3[1]);
    }
}