class Solution {
    static int findOutlier(int[] integers){
        int even = 0;
        int odd = 0;
        int evenNum = 0;
        int oddNum = 0;
        for (int i=0; i<integers.length; i++) {
            if (integers[i] % 2 == 0) {
                even++;
                evenNum = integers[i];
            } else {
                odd++;
                oddNum = integers[i];
            }
        }
        if (even > 1) {
            return oddNum;
        } else {
            return evenNum;
        }
    }
}