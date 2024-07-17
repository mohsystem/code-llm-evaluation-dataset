public class Main {
    public static void main(String[] args) {
        int[] seq = {1,2,2,3,3,3,4,3,3,3,2,2,1};
        int result = findOdd(seq);
        System.out.println(result);
    }

    public static int findOdd(int[] seq) {
        int result = 0;
        for (int i : seq) {
            int count = 0;
            for (int j : seq) {
                if (i == j) {
                    count++;
                }
            }
            if (count % 2 != 0) {
                result = i;
            }
        }
        return result;
    }
}