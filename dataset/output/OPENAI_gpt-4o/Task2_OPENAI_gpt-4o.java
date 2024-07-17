public class Main {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        System.out.println(createPhoneNumber(numbers));
    }

    public static String createPhoneNumber(int[] numbers) {
        return String.format("(%d%d%d) %d%d%d-%d%d%d%d", 
                              numbers[0], numbers[1], numbers[2], 
                              numbers[3], numbers[4], numbers[5], 
                              numbers[6], numbers[7], numbers[8], numbers[9]);
    }
}