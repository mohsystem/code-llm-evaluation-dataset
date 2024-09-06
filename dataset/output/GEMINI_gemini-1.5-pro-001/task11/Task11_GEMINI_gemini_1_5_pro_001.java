public class Task11_GEMINI_gemini_1_5_pro_001 {

    public static int nbYear(int p0, double percent, int aug, int p) {
        int years = 0;
        while (p0 < p) {
            p0 = (int) (p0 + p0 * (percent / 100) + aug);
            years++;
        }
        return years;
    }

    public static void main(String[] args) {
        System.out.println(nbYear(1500, 5, 100, 5000)); 
        System.out.println(nbYear(1500000, 2.5, 10000, 2000000)); 
    }
}