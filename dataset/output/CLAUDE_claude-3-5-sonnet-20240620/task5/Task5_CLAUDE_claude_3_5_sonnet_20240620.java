
public class Task5_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int persistence(long num) {
        if (num < 10) {
            return 0;
        }
        
        long product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        
        return 1 + persistence(product);
    }

    public static void main(String[] args) {
        System.out.println(persistence(39));  // Output: 3
        System.out.println(persistence(999)); // Output: 4
        System.out.println(persistence(4));   // Output: 0
    }
}
