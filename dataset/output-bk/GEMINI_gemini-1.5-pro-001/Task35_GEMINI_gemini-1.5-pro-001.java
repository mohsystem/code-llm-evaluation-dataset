public class BusPassengers {

    public static int getNumberOfPeopleOnBus(int[][] busStops) {
        int peopleOnBus = 0;

        for (int[] stop : busStops) {
            peopleOnBus += stop[0] - stop[1];
        }

        return peopleOnBus;
    }

    public static void main(String[] args) {
        // Test cases
        int[][] busStops1 = {{10, 0}, {3, 5}, {5, 8}};
        int[][] busStops2 = {{3, 0}, {9, 1}, {4, 10}, {12, 2}, {6, 1}, {7, 10}};
        int[][] busStops3 = {{3, 0}, {9, 1}, {4, 8}, {12, 2}, {6, 1}, {7, 8}};

        System.out.println(getNumberOfPeopleOnBus(busStops1)); // 5
        System.out.println(getNumberOfPeopleOnBus(busStops2)); // 17
        System.out.println(getNumberOfPeopleOnBus(busStops3)); // 21
    }
}