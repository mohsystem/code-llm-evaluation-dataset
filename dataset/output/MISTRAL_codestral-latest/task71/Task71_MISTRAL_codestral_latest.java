public class Task71_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            int num = Integer.parseInt(args[0]);
            System.out.println(num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter an integer.");
        }
    }
}