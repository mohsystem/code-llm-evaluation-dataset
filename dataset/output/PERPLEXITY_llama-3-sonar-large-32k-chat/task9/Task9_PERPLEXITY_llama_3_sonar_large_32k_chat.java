public class Task9_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        System.out.println(oddOrEven(new int[]{0}));  // Output: "even"
        System.out.println(oddOrEven(new int[]{0, 1, 4}));  // Output: "odd"
        System.out.println(oddOrEven(new int[]{0, -1, -5}));  // Output: "even"
    }

    public static String oddOrEven(int[] arr) {
        return (arr.length == 0) ? "even" : (sum(arr) % 2 == 0) ? "even" : "odd";
    }

    public static int sum(int[] arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return sum;
    }
}