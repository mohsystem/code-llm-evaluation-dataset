public class Main {
    public static void main(String[] args) {
        int[][] people = {{10, 0}, {3, 5}, {5, 8}};
        int remainingPeople = 0;
        for (int[] pair : people) {
            remainingPeople += pair[0] - pair[1];
        }
        System.out.println(remainingPeople);
    }
}