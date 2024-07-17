public class Main {
    public static boolean xorGame(int[] nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        return xorSum == 0 || nums.length % 2 == 0;
    }
    
    public static void main(String[] args) {
        // Testing example 1
        System.out.println(xorGame(new int[] {1, 1, 2}));  // False
        // Testing example 2
        System.out.println(xorGame(new int[] {0, 1}));  // True
        // Testing example 3
        System.out.println(xorGame(new int[] {1, 2, 3}));  // True
    }
}