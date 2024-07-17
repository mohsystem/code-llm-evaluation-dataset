import java.util.Arrays;
class Solution {
    public static int solveSuperMarketQueue(int[] customers, int n) {
      if (customers.length==0) return 0;
      if (customers.length<=n) return Arrays.stream(customers).max().getAsInt();
      int[] tills = new int[n];
      int customerIndex = 0;
      for (int i=0; i<n; i++) {
        tills[i]=customers[customerIndex];
        customerIndex++;
      }
      while (customerIndex<customers.length) {
        int nextTill = findMinIndex(tills);
        tills[nextTill]+=customers[customerIndex];
        customerIndex++;
      }
      return Arrays.stream(tills).max().getAsInt();
    }
  
    private static int findMinIndex(int[] arr) {
        int minIndex = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    } 
}