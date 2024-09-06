public class Task23_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(findNb(1071225));  // 45
        System.out.println(findNb(91716553919377L));  // -1
    }

    public static long findNb(long m) {
        long n = 0, totalVolume = 0;
        while (totalVolume < m) {
            n++;
            totalVolume += Math.pow(n, 3);
        }
        return totalVolume == m ? n : -1;
    }
}