import java.util.*;

public class Main {
    public static int peopleOnBus(int[][] busStops) {
        int people = 0;
        for (int[] stop : busStops) {
            people += stop[0];
            people -= stop[1];
        }
        return people;
    }

    public static void main(String[] args) {
        int[][] busStops = {{3, 0}, {2, 1}, {5, 3}, {2, 2}};
        System.out.println(peopleOnBus(busStops));
    }
}