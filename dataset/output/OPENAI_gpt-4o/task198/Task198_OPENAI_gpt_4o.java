import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;

public class Task198_OPENAI_gpt_4o {
    private static Random rand = new Random();
    
    private static int rand7() {
        return rand.nextInt(7) + 1;
    }
    
    public static int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) {
                return (num - 1) % 10 + 1;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> results = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            results.add(rand10());
        }
        System.out.println(results);
        scanner.close();
    }
}