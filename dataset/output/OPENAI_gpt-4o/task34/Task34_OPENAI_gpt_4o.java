public class Task34_OPENAI_gpt_4o {
    public static boolean isNarcissistic(int number) {
        String numStr = String.valueOf(number);
        int power = numStr.length();
        int sum = 0;
        
        for (char c : numStr.toCharArray()) {
            int digit = c - '0';
            sum += Math.pow(digit, power);
        }

        return sum == number;
    }

    public static void main(String[] args) {
        System.out.println(isNarcissistic(153));  // true
        System.out.println(isNarcissistic(1652));  // false
    }
}