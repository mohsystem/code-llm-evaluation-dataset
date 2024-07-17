public class Main {
    public static boolean validatePin(String pin) {
        if (pin.length() == 4 || pin.length() == 6) {
            for (char c : pin.toCharArray()) {
                if (!Character.isDigit(c)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(validatePin("1234")); // true
        System.out.println(validatePin("12345")); // false
        System.out.println(validatePin("a234")); // false
    }
}