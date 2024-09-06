import java.util.Random;

public class Task197_PERPLEXITY_llama_3_sonar_large_32k_chat {

    private double radius;
    private double x_center;
    private double y_center;
    private Random random;

    public Task197_PERPLEXITY_llama_3_sonar_large_32k_chat(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
        this.random = new Random();
    }

    public double[] randPoint() {
        double r = Math.sqrt(random.nextDouble()) * radius;
        double theta = random.nextDouble() * 2 * Math.PI;
        return new double[]{x_center + r * Math.cos(theta), y_center + r * Math.sin(theta)};
    }
}