import java.util.Arrays;
import java.util.List;

public class Task35_OPENAI_gpt_4o {
    public static int numberOfPeople(List<int[]> busStops) {
        int totalPeople = 0;
        for (int[] stop : busStops) {
            totalPeople += stop[0];
            totalPeople -= stop[1];
        }
        return totalPeople;
    }

    public static void main(String[] args) {
        List<int[]> busStops = Arrays.asList(new int[]{10, 0}, new int[]{3, 5}, new int[]{5, 8});
        System.out.println(numberOfPeople(busStops)); // Output: 5
    }
}