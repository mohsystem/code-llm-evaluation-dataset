class Solution {
    public static double findUniq(double arr[]) {
        if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
        for (int i = 1; i < arr.length; i++)
            if (arr[i] != arr[i - 1]) return arr[i];
        return 0;
    }
}