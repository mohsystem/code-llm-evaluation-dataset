import java.util.*;

public class Task71_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please provide a string to convert.");
            return;
        }
        String inputStr = args[0];
        try {
            int convertedInt = Integer.parseInt(inputStr);
            System.out.println("Converted integer: " + convertedInt);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: Not a valid integer.");
        }
    }
}