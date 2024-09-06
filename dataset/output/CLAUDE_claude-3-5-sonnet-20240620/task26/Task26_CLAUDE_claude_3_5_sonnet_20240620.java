
public class Task26_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int findOdd(int[] arr) {
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(findOdd(new int[]{7}));
        System.out.println(findOdd(new int[]{0}));
        System.out.println(findOdd(new int[]{1,1,2}));
        System.out.println(findOdd(new int[]{0,1,0,1,0}));
        System.out.println(findOdd(new int[]{1,2,2,3,3,3,4,3,3,3,2,2,1}));
    }
}
