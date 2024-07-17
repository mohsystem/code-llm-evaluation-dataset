import java.util.ArrayList;
import java.util.List;

public class Bus {
    public static void main(String[] args) {
        List<int[]> stops = new ArrayList<>();
        stops.add(new int[] {10, 0});
        stops.add(new int[] {3, 5});
        stops.add(new int[] {2, 5});

        System.out.println(peopleOnTheBus(stops)); // Output should be 5
    }

    public static int peopleOnTheBus(List<int[]> stops) {
        int peopleOnBus = 0;
        for (int[] stop : stops) {
            peopleOnBus += stop[0] - stop[1];
        }
        return peopleOnBus;
    }
}