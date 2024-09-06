public class Task71_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        try {
            int num = Integer.parseInt(args[0]);
            System.out.println("The integer value is: " + num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid integer.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("No input provided. Please provide a command line argument.");
        }
    }
}