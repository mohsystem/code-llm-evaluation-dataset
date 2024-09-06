public class Task26_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int findOdd(int[] arr) {
        for (int num : arr) {
            int count = 0;
            for (int i : arr) {
                if (i == num) {
                    count++;
                }
            }
            if (count % 2 != 0) {
                return num;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {1,2,2,3,3,3,4,3,3,3,2,2,1};
        System.out.println(findOdd(arr));
    }
}