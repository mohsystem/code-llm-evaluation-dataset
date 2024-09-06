public class Task167_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        System.out.println(cubeDiagonal(8));
        System.out.println(cubeDiagonal(343));
        System.out.println(cubeDiagonal(1157.625));
    }
    public static double cubeDiagonal(double volume) {
        return Math.round(Math.sqrt(3) * Math.pow(volume, 1. / 3) * 100.0) / 100.0;
    }
}