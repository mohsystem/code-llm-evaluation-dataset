
public class Task71_CLAUDE_claude_3_5_sonnet_20240620 {
    public static Integer convertToInt(String input) {
        try {
            return Integer.parseInt(input);
        } catch (NumberFormatException e) {
            return null;
        }
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task71_CLAUDE_claude_3_5_sonnet_20240620 <string>");
            System.exit(1);
        }

        String input = args[0];
        Integer result = convertToInt(input);

        if (result != null) {
            System.out.println("Converted integer: " + result);
        } else {
            System.out.println("Invalid input: Cannot convert to integer");
        }
    }
}
