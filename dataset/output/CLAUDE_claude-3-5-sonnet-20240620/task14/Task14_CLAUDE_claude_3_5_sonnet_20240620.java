
public class Task14_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int findEvenIndex(int[] arr) {
        int leftSum = 0;
        int rightSum = 0;
        
        for (int num : arr) {
            rightSum += num;
        }
        
        for (int i = 0; i < arr.length; i++) {
            rightSum -= arr[i];
            
            if (leftSum == rightSum) {
                return i;
            }
            
            leftSum += arr[i];
        }
        
        return -1;
    }
}
