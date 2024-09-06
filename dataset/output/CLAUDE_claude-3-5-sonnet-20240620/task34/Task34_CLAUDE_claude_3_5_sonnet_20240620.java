
public class Task34_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean narcissistic(int number) {
        String numStr = String.valueOf(number);
        int power = numStr.length();
        int sum = 0;
        
        for (char digit : numStr.toCharArray()) {
            sum += Math.pow(Character.getNumericValue(digit), power);
        }
        
        return sum == number;
    }

    public static void main(String[] args) {
        System.out.println(narcissistic(153));  // true
        System.out.println(narcissistic(1652));  // false
    }
}
