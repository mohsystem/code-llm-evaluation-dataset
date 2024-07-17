
public class Solution {
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
    
    public static void main(String[] args) {
        int[] arr1 = {1,2,3,4,3,2,1};
        int[] arr2 = {1,100,50,-51,1,1};
        int[] arr3 = {20,10,-80,10,10,15,35};
        
        System.out.println(findEvenIndex(arr1));
        System.out.println(findEvenIndex(arr2));
        System.out.println(findEvenIndex(arr3));
    }
}
