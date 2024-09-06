
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

class Solution {
    private static Random random = new Random();

    private static int rand7() {
        return random.nextInt(7) + 1;
    }

    public static int rand10() {
        while (true) {
            int result = (rand7() - 1) * 7 + (rand7() - 1);
            if (result < 40) {
                return result % 10 + 1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of times to call rand10(): ");
        int n = scanner.nextInt();
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(rand10());
        }
        
        System.out.println(result);
        scanner.close();
    }
}
