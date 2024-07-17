public class Population {

    public static int nb_year(int p0, double percent, int aug, int p) {
        int years = 0;
        while (p0 < p) {
            p0 += p0 * percent / 100 + aug;
            years++;
        }
        return years;
    }

    public static void main(String[] args) {
        System.out.println(nb_year(1000, 2, 50, 1200)); // 3
        System.out.println(nb_year(1500, 5, 100, 5000)); // 15
        System.out.println(nb_year(1500000, 2.5, 10000, 2000000)); // 10
    }

}