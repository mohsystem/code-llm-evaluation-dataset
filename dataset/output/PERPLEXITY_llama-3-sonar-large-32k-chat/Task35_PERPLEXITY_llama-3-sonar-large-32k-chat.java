public class Main {
    public static int peopleOnBus(int[][] stops) {
        int people = 0;
        for (int[] stop : stops) {
            people += stop[0] - stop[1];
        }
        return people;
    }
    public static void main(String[] args) {
        int[][] stops = {{10, 0}, {3, 5}, {5, 8}};
        System.out.println(peopleOnBus(stops));
    }
}