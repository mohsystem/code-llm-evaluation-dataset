import java.util.ArrayList;

class BusStops {
    public static int number(ArrayList<int[]> busStops) {
        int peopleInBus = 0;
        for (int[] stop : busStops) {
            peopleInBus += stop[0] - stop[1];
        }
        return peopleInBus;
    }
}