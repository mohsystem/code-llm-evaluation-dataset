public class Task35_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int number_of_people_still_on_bus(int[][] lst) {
        int people_on_bus = 0;
        for (int[] pair : lst) {
            people_on_bus += pair[0] - pair[1];
        }
        return people_on_bus;
    }
}