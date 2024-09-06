import java.util.*;

public class Task1_OPENAI_gpt_4o {
    public static int numberOfPeopleOnBus(int[][] busStops) {
        int peopleOnBus = 0;
        for (int[] stop : busStops) {
            peopleOnBus += stop[0] - stop[1];
        }
        return peopleOnBus;
    }

    public static void main(String[] args) {
        int[][] busStops = { { 3, 0 }, { 2, 1 }, { 5, 2 }, { 1, 4 } };
        System.out.println(numberOfPeopleOnBus(busStops));
    }
}