public class Task71_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an argument to be converted to an integer.");
            return;
        }

        try {
            String userInput = args[0];
            int convertedInteger = Integer.parseInt(userInput);
            System.out.println("Successfully converted '" + userInput + "' to integer: " + convertedInteger);
        } catch (NumberFormatException e) {
            System.out.println("Unable to convert '" + args[0] + "' to an integer.");
        }
    }
}