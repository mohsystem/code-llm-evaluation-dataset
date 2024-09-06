public class Task142_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.loadLibrary("solution");
        // Assuming you have the native method declared as:
        // public static native int gcd(int a, int b);

        int a = 25;
        int b = 15;
        System.out.println("Greatest Common Divisor: " + gcd(a, b));
    }

    public static native int gcd(int a, int b);
}