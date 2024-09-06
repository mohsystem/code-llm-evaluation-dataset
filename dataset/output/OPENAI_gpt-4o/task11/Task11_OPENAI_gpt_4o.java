public class Task11_OPENAI_gpt_4o {
    public static int nbYear(int p0, double percent, int aug, int p) {
        int year = 0;
        while (p0 < p) {
            p0 += (int)(p0 * percent / 100) + aug;
            year += 1;
        }
        return year;
    }

    public static void main(String[] args) {
        System.out.println(nbYear(1000, 2, 50, 1200));  // Example usage
    }
}