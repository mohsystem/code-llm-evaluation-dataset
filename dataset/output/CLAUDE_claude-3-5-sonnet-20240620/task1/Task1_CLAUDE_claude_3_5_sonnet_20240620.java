
public class Task1_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int countPassengers(ArrayList<int[]> stops) {
        return stops.stream().mapToInt(stop -> stop[0] - stop[1]).sum();
    }
}
