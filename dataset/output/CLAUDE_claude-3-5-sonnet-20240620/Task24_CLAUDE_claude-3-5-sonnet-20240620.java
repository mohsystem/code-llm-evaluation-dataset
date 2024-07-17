
public class Solution {
    public static boolean validatePin(String pin) {
        return pin.matches("\\\\d{4}|\\\\d{6}");
    }
}
