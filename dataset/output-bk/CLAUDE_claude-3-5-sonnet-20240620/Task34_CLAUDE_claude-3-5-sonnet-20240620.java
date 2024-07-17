
public class NarcissisticNumber {
    public static boolean isNarcissistic(int number) {
        String numStr = String.valueOf(number);
        int length = numStr.length();
        int sum = 0;
        
        for (char digit : numStr.toCharArray()) {
            sum += Math.pow(Character.getNumericValue(digit), length);
        }
        
        return sum == number;
    }

    public static void main(String[] args) {
        System.out.println(isNarcissistic(153));  // true
        System.out.println(isNarcissistic(1652)); // false
    }
}
