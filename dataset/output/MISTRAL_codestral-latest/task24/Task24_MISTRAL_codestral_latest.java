public class Task24_MISTRAL_codestral_latest {
    public static boolean validatePin(String pin) {
        return (pin.length() == 4 || pin.length() == 6) && pin.matches("\\d+");
    }
}