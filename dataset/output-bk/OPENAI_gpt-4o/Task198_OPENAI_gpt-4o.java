import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n = 3;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(rand10());
        }
        System.out.println(result);
    }

    public static int rand7() {
        return new Random().nextInt(7) + 1;
    }

    public static int rand10() {
        while (true) {
            int x = (rand7() - 1) * 7 + rand7();
            if (x <= 40) {
                return 1 + (x - 1) % 10;
            }
        }
    }
}