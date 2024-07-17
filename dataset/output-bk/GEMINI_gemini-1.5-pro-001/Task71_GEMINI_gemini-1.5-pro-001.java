import java.lang.NumberFormatException;
public class StringToInteger {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an argument.");
            return;
        }
        try {
            int intValue = Integer.parseInt(args[0]);
            System.out.println("The integer value is: " + intValue);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid integer.");
        }
    }
}